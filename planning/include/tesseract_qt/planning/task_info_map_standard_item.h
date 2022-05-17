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
#ifndef TESSERACT_QT_PLANNING_TASK_INFO_MAP_STANDARD_ITEM_H
#define TESSERACT_QT_PLANNING_TASK_INFO_MAP_STANDARD_ITEM_H

#include <QStandardItem>
#include <memory>
#include <map>

namespace tesseract_planning
{
class TaskInfo;
}

namespace tesseract_gui
{
class TaskInfoMapStandardItem : public QStandardItem
{
public:
  explicit TaskInfoMapStandardItem(
      const std::map<std::size_t, std::unique_ptr<tesseract_planning::TaskInfo>>& task_info_map);
  TaskInfoMapStandardItem(const QString& text,
                          const std::map<std::size_t, std::unique_ptr<tesseract_planning::TaskInfo>>& task_info_map);
  TaskInfoMapStandardItem(const QIcon& icon,
                          const QString& text,
                          const std::map<std::size_t, std::unique_ptr<tesseract_planning::TaskInfo>>& task_info_map);
  int type() const override;

private:
  void ctor(const std::map<std::size_t, std::unique_ptr<tesseract_planning::TaskInfo>>& task_info_map);
};
}  // namespace tesseract_gui

#endif  // TESSERACT_QT_PLANNING_TASK_INFO_MAP_STANDARD_ITEM_H
