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

#ifndef NODE_H
#define NODE_H

class Layer;
class Node;

#include <QList>
#include <QString>
#include <QTime>
#include <QByteArray>
#include <QList>

class Node
{
public:
    Node(Layer *layer, Node *parent, QString name="");
    virtual ~Node();
    
    QByteArray pack(QTime t);
    QString name();
    void setName(QString name);
    
    bool appendChild(Node *child);
    bool removeChild(Node *child);
    Node *childAt(int index);
    
    virtual QString typeString() const;
    
private:
    QString m_name;
    QList<Node *> m_children;
    Layer *m_layer;
    Node *m_parent;
};

#endif
