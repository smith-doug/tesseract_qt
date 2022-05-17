/**
 * @author Levi Armstrong <levi.armstrong@gmail.com>
 *
 * @copyright Copyright (C) 2022 Levi Armstrong <levi.armstrong@gmail.com>
 *
 * @par License
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * @par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * @par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * @par
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <tesseract_qt/environment/commands/remove_allowed_collision_command_standard_item.h>
#include <tesseract_qt/common/standard_item_utils.h>
#include <tesseract_qt/common/standard_item_type.h>
#include <tesseract_qt/common/icon_utils.h>

namespace tesseract_gui
{
RemoveAllowedCollisionCommandStandardItem::RemoveAllowedCollisionCommandStandardItem(
    tesseract_environment::RemoveAllowedCollisionCommand::ConstPtr command)
  : QStandardItem(icons::getCommandEntryIcon(), "Remove Allowed Collision"), command(std::move(command))
{
  ctor();
}

RemoveAllowedCollisionCommandStandardItem::RemoveAllowedCollisionCommandStandardItem(
    const QString& text,
    tesseract_environment::RemoveAllowedCollisionCommand::ConstPtr command)
  : QStandardItem(icons::getCommandEntryIcon(), text), command(std::move(command))
{
  ctor();
}

RemoveAllowedCollisionCommandStandardItem::RemoveAllowedCollisionCommandStandardItem(
    const QIcon& icon,
    const QString& text,
    tesseract_environment::RemoveAllowedCollisionCommand::ConstPtr command)
  : QStandardItem(icon, text), command(std::move(command))
{
  ctor();
}

int RemoveAllowedCollisionCommandStandardItem::type() const
{
  return static_cast<int>(StandardItemType::ENV_COMMAND_REMOVE_ALLOWED_COLLISION);
}

void RemoveAllowedCollisionCommandStandardItem::ctor()
{
  appendRow(createStandardItemString("Link Name 1", command->getLinkName1()));
  appendRow(createStandardItemString("Link Name 2", command->getLinkName2()));
}
}  // namespace tesseract_gui
