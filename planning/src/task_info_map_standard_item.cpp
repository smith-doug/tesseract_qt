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
#include <tesseract_qt/planning/task_info_map_standard_item.h>
#include <tesseract_qt/planning/task_info_standard_item.h>

#include <tesseract_qt/common/standard_item_type.h>
#include <tesseract_qt/common/standard_item_utils.h>
#include <tesseract_qt/common/icon_utils.h>

#include <tesseract_process_managers/core/task_info.h>

namespace tesseract_gui
{
TaskInfoMapStandardItem::TaskInfoMapStandardItem(
    const std::map<std::size_t, std::unique_ptr<tesseract_planning::TaskInfo>>& task_info_map)
  : QStandardItem(icons::getUnknownIcon(), "Task Info Map")
{
  ctor(task_info_map);
}

TaskInfoMapStandardItem::TaskInfoMapStandardItem(
    const QString& text,
    const std::map<std::size_t, std::unique_ptr<tesseract_planning::TaskInfo>>& task_info_map)
  : QStandardItem(icons::getUnknownIcon(), text)
{
  ctor(task_info_map);
}

TaskInfoMapStandardItem::TaskInfoMapStandardItem(
    const QIcon& icon,
    const QString& text,
    const std::map<std::size_t, std::unique_ptr<tesseract_planning::TaskInfo>>& task_info_map)
  : QStandardItem(icon, text)
{
  ctor(task_info_map);
}

int TaskInfoMapStandardItem::type() const { return static_cast<int>(StandardItemType::MP_TASK_INFO_MAP); }

void TaskInfoMapStandardItem::ctor(
    const std::map<std::size_t, std::unique_ptr<tesseract_planning::TaskInfo>>& task_info_map)
{
  for (const auto& pair : task_info_map)
    appendRow(new TaskInfoStandardItem(QString("%1").arg(pair.first), *pair.second));
}
}  // namespace tesseract_gui
