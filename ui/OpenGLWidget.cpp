/* Team210 Demotool 
 * Copyright (C) 2019  Alexander Kraus <nr4@z10.info>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "OpenGLWidget.hpp"
#include "config.h"
#include <QOpenGLFunctions>
#include <QDebug>

const GLfloat vertices[] = {
    -1, -1, 0,
    -1,  1, 0,
     1,  1, 0,
     1, -1, 0
};

const GLubyte indices[] = {
    0, 1, 2,
    0, 2, 3
};

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{
    m_vbo.destroy();
    delete m_prog;
}

void OpenGLWidget::initializeGL()
{
    m_prog = new QOpenGLShaderProgram();
    m_prog->addShaderFromSourceFile(QOpenGLShader::Vertex, VERT_SHADER_FILE);
    m_prog->addShaderFromSourceFile(QOpenGLShader::Fragment, FRAG_SHADER_FILE);
    m_prog->link();
    m_prog->bind();

    m_vbo.create();
    m_vbo.bind();
    m_prog->setAttributeArray(0, vertices, 3);
    m_prog->enableAttributeArray(0);

    counter = 0;
    data = QImage(10, 10, QImage::Format_ARGB32); // TODO test for nullptr
    data.fill(counter | 0xFF000000);
    m_text = new QOpenGLTexture(data);

    m_text->bind(0);
    m_prog->setUniformValue("iData", 0);

    m_vbo.release();
    m_prog->release();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    m_prog->bind();
    m_prog->setUniformValue("iResolution", w, h);
    m_prog->release();
}

void OpenGLWidget::paintGL()
{
    counter += 1;
    data.fill(counter | 0xFF000000);
    m_text = new QOpenGLTexture(data);
    m_prog->bind();
    qDebug() << counter;
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    {
        m_vbo.bind();
        m_text->bind();
        f->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
        m_text->release();
        m_vbo.release();
    }
    m_prog->release();
}
