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

#include "Node.hpp"
#include "Layer.hpp"

Node::Node(Layer *layer, Node *parent, QString name)
    : m_name(name)
    , m_layer(layer)
    , m_parent(parent)
{
}

Node * Node::childAt(int index)
{
    if(m_children.length() <= index || index < 0) return nullptr;
    
    return m_children.at(index);
}

bool Node::appendChild(Node* child)
{
    return m_children.push_back(child);
}

QString Node::name()
{
    return m_name;
}


