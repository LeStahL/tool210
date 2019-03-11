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

#ifndef LAYER_H
#define LAYER_H

#include <QList>
#include <QString>
#include <QTime>
#include <QJsonDocument>

class Keyframe;
class Node;

class Layer
{
public:
    Layer(QString filename="");
    virtual ~Layer();
    
    Keyframe *keyframeBefore(QTime t);
    Keyframe *keyframeAfter(QTime t);
    Keyframe *keyframeAt(QTime t);
    Keyframe *insertFrameAt(QTime t);
    
    int indexOf(Keyframe *frame);
    Keyframe *keyframe(int index);
    
    bool contains(Keyframe *frame);
    
    QByteArray pack(QTime t);
    
    QJsonDocument toJSON();
    bool fromJSON(QJsonDocument d);
    
    QString filename();
    void setFilename(QString name);
    
private:
    QList<Keyframe *> m_keyframes;
    QString m_filename;
    Node *m_root;
};


#endif
