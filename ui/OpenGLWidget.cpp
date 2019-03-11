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
    m_vert.destroy();
    delete m_prog;
}

void OpenGLWidget::initializeGL()
{
    qDebug() << "GL: Init";
    m_prog = new QOpenGLShaderProgram();
    m_prog->addShaderFromSourceFile(QOpenGLShader::Vertex, VERT_SHADER_FILE);
    m_prog->addShaderFromSourceFile(QOpenGLShader::Fragment, FRAG_SHADER_FILE);
    m_prog->link();
    m_prog->bind();

    m_vert.create();
    m_vert.bind();
    m_vert.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vert.allocate(vertices, sizeof(vertices));

    m_vbo.create();
    m_vbo.bind();
    m_prog->enableAttributeArray(0);
    m_prog->setAttributeBuffer(0, GL_FLOAT, 0, 3);

    m_vert.release();
    m_vbo.release();
    m_prog->release();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    qDebug() << "GL: Resize";
}

void OpenGLWidget::paintGL()
{
    qDebug() << "GL: Paint";
    m_prog->bind();
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    {
        m_vbo.bind();
        f->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
        m_vbo.release();
    }
    m_prog->release();
}
