/*!
 * Author: mocibb mocibb@163.com
 * Group:  CarrotSLAM https://github.com/mocibb/CarrotSLAM
 * Name:   mappoint.h
 * Date:   2015.10.02
 * Func:   mappoint is feature that no associates with any frame
 *
 *
 * The MIT License (MIT)
 * Copyright (c) 2015 CarrotSLAM Group
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef TYPES_MAPPOINT_H_
#define TYPES_MAPPOINT_H_
#include <Eigen/Core>
#include "core/carrot_slam.h"

namespace carrotslam {
/*! \brief patch object represents point and semi-dense features.
 */
struct Patch {
  Eigen::Vector2f center;
  int half_size;
  int level;
};
typedef std::shared_ptr<Patch> PatchPtr;
/*! \brief
 *
 *
 *  MapPoint是不依赖与Frame的特征点
 *
 */
class MapPoint : public ISLAMData {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  Eigen::Vector3f pos; //!< 位置
  Eigen::Vector3f pos_range[2]; //!< 深度范围
  int level;
  PatchPtr patch; //!< 保存图像信息
};

}  // namespace carrotslam

#endif /* TYPES_MAPPOINT_H_ */
