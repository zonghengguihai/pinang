// -*-c++-*-

#ifndef PINANG_GEOMETRY_H
#define PINANG_GEOMETRY_H

#include "vec3d.hpp"
#include "group.hpp"

namespace pinang {

class Group;

class Quaternion
{
 public:
  Quaternion(): w_(0.0), x_(0.0), y_(0.0), z_(0.0) {}
  Quaternion(double w, double x, double y, double z): w_(w), x_(x), y_(y), z_(z) {}

  double w() const {return w_;}
  double x() const {return x_;}
  double y() const {return y_;}
  double z() const {return z_;}
  int normalize();

 protected:
  double w_;
  double x_;
  double y_;
  double z_;
};

class Transform
{
 public:
  Transform();
  Transform(Quaternion, Vec3d);

  Quaternion rotation() { return rotation_; }
  Vec3d translation() { return translation_; }
  void set_rotation(Quaternion);
  void set_translation(Vec3d v) { translation_ = v; }

  Vec3d apply(const Vec3d&);
  Group apply(Group&);

 protected:
  Quaternion rotation_;
  Vec3d translation_;

  // three vec3d for rotation matrix;
  Vec3d rotv1_;
  Vec3d rotv2_;
  Vec3d rotv3_;
};


}

#endif
