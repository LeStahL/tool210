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

#include "Constant.hpp"
#include "Layer.hpp"
#include "Node.hpp"

Constant::Constant(Layer* layer, Node* parent, QString name, QVariant value)
    : Node(layer, parent, name)
    , m_value(value)
{
}

void Constant::setValue(QVariant value)
{
    m_value = value;
}

QVariant Constant::value()
{
    return m_value;
}

QString Constant::typeString() const
{
    return QString("Constant");
}
