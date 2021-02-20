/*
 *  C API for the libfive standard library
 *
 *  DO NOT EDIT BY HAND!
 *  This file is automatically generated from libfive/stdlib/stdlib.h
 *
 *  It was last generated on 2021-02-20 13:49:51 by user mkeeter
 */
#include "stdlib.h"
#include "stdlib_impl.hpp"

using namespace libfive;
////////////////////////////////////////////////////////////////////////////////
// csg
LIBFIVE_STDLIB _union(libfive_tree a, libfive_tree b) {
    return _union(Tree(a), Tree(b)).release();
}
LIBFIVE_STDLIB intersection(libfive_tree a, libfive_tree b) {
    return intersection(Tree(a), Tree(b)).release();
}
LIBFIVE_STDLIB inverse(libfive_tree a) {
    return inverse(Tree(a)).release();
}
LIBFIVE_STDLIB difference(libfive_tree a, libfive_tree b) {
    return difference(Tree(a), Tree(b)).release();
}
LIBFIVE_STDLIB offset(libfive_tree a, libfive_float o) {
    return offset(Tree(a), Tree(o)).release();
}
LIBFIVE_STDLIB clearance(libfive_tree a, libfive_tree b, libfive_float offset) {
    return clearance(Tree(a), Tree(b), Tree(offset)).release();
}
LIBFIVE_STDLIB shell(libfive_tree a, libfive_float offset) {
    return shell(Tree(a), Tree(offset)).release();
}
LIBFIVE_STDLIB blend_expt(libfive_tree a, libfive_tree b, libfive_float m) {
    return blend_expt(Tree(a), Tree(b), Tree(m)).release();
}
LIBFIVE_STDLIB blend_expt_unit(libfive_tree a, libfive_tree b, libfive_float m) {
    return blend_expt_unit(Tree(a), Tree(b), Tree(m)).release();
}
LIBFIVE_STDLIB blend_rough(libfive_tree a, libfive_tree b, libfive_float m) {
    return blend_rough(Tree(a), Tree(b), Tree(m)).release();
}
LIBFIVE_STDLIB blend_difference(libfive_tree a, libfive_tree b, libfive_float m, libfive_float o) {
    return blend_difference(Tree(a), Tree(b), Tree(m), Tree(o)).release();
}
LIBFIVE_STDLIB morph(libfive_tree a, libfive_tree b, libfive_float m) {
    return morph(Tree(a), Tree(b), Tree(m)).release();
}
LIBFIVE_STDLIB loft(libfive_tree a, libfive_tree b, libfive_float zmin, libfive_float zmax) {
    return loft(Tree(a), Tree(b), Tree(zmin), Tree(zmax)).release();
}
LIBFIVE_STDLIB loft_between(libfive_tree a, libfive_tree b, tvec3 lower, tvec3 upper) {
    return loft_between(Tree(a), Tree(b), TreeVec3{Tree(lower.x), Tree(lower.y), Tree(lower.z)}, TreeVec3{Tree(upper.x), Tree(upper.y), Tree(upper.z)}).release();
}
////////////////////////////////////////////////////////////////////////////////
// shapes
LIBFIVE_STDLIB circle(libfive_float r, tvec2 center) {
    return circle(Tree(r), TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB ring(libfive_float ro, libfive_float ri, tvec2 center) {
    return ring(Tree(ro), Tree(ri), TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB polygon(libfive_float r, int n, tvec2 center) {
    return polygon(Tree(r), n, TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB rectangle(tvec2 a, tvec2 b) {
    return rectangle(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}).release();
}
LIBFIVE_STDLIB rounded_rectangle(tvec2 a, tvec2 b, libfive_float r) {
    return rounded_rectangle(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}, Tree(r)).release();
}
LIBFIVE_STDLIB rectangle_exact(tvec2 a, tvec2 b) {
    return rectangle_exact(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}).release();
}
LIBFIVE_STDLIB rectangle_centered_exact(tvec2 size, tvec2 center) {
    return rectangle_centered_exact(TreeVec2{Tree(size.x), Tree(size.y)}, TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB triangle(tvec2 a, tvec2 b, tvec2 c) {
    return triangle(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}, TreeVec2{Tree(c.x), Tree(c.y)}).release();
}
LIBFIVE_STDLIB box_mitered(tvec3 a, tvec3 b) {
    return box_mitered(TreeVec3{Tree(a.x), Tree(a.y), Tree(a.z)}, TreeVec3{Tree(b.x), Tree(b.y), Tree(b.z)}).release();
}
LIBFIVE_STDLIB box_mitered_centered(tvec3 size, tvec3 center) {
    return box_mitered_centered(TreeVec3{Tree(size.x), Tree(size.y), Tree(size.z)}, TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB box_exact_centered(tvec3 size, tvec3 center) {
    return box_exact_centered(TreeVec3{Tree(size.x), Tree(size.y), Tree(size.z)}, TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB box_exact(tvec3 a, tvec3 b) {
    return box_exact(TreeVec3{Tree(a.x), Tree(a.y), Tree(a.z)}, TreeVec3{Tree(b.x), Tree(b.y), Tree(b.z)}).release();
}
LIBFIVE_STDLIB box_rounded(tvec3 a, tvec3 b, libfive_float r) {
    return box_rounded(TreeVec3{Tree(a.x), Tree(a.y), Tree(a.z)}, TreeVec3{Tree(b.x), Tree(b.y), Tree(b.z)}, Tree(r)).release();
}
LIBFIVE_STDLIB sphere(libfive_float radius, tvec3 center) {
    return sphere(Tree(radius), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB half_space(tvec3 norm, tvec3 point) {
    return half_space(TreeVec3{Tree(norm.x), Tree(norm.y), Tree(norm.z)}, TreeVec3{Tree(point.x), Tree(point.y), Tree(point.z)}).release();
}
LIBFIVE_STDLIB cylinder_z(libfive_float r, libfive_float h, tvec3 base) {
    return cylinder_z(Tree(r), Tree(h), TreeVec3{Tree(base.x), Tree(base.y), Tree(base.z)}).release();
}
LIBFIVE_STDLIB cone_ang_z(libfive_float angle, libfive_float height, tvec3 base) {
    return cone_ang_z(Tree(angle), Tree(height), TreeVec3{Tree(base.x), Tree(base.y), Tree(base.z)}).release();
}
LIBFIVE_STDLIB cone_z(libfive_float radius, libfive_float height, tvec3 base) {
    return cone_z(Tree(radius), Tree(height), TreeVec3{Tree(base.x), Tree(base.y), Tree(base.z)}).release();
}
LIBFIVE_STDLIB pyramid_z(tvec2 a, tvec2 b, libfive_float zmin, libfive_float height) {
    return pyramid_z(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}, Tree(zmin), Tree(height)).release();
}
LIBFIVE_STDLIB torus_z(libfive_float ro, libfive_float ri, tvec3 center) {
    return torus_z(Tree(ro), Tree(ri), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB gyroid(tvec3 period, libfive_float thickness) {
    return gyroid(TreeVec3{Tree(period.x), Tree(period.y), Tree(period.z)}, Tree(thickness)).release();
}
LIBFIVE_STDLIB array_x(libfive_tree shape, int nx, libfive_float dx) {
    return array_x(Tree(shape), nx, Tree(dx)).release();
}
LIBFIVE_STDLIB array_xy(libfive_tree shape, int nx, int ny, tvec2 delta) {
    return array_xy(Tree(shape), nx, ny, TreeVec2{Tree(delta.x), Tree(delta.y)}).release();
}
LIBFIVE_STDLIB array_xyz(libfive_tree shape, int nx, int ny, int nz, tvec3 delta) {
    return array_xyz(Tree(shape), nx, ny, nz, TreeVec3{Tree(delta.x), Tree(delta.y), Tree(delta.z)}).release();
}
LIBFIVE_STDLIB array_polar_z(libfive_tree shape, int n, tvec2 center) {
    return array_polar_z(Tree(shape), n, TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB extrude_z(libfive_tree t, libfive_float zmin, libfive_float zmax) {
    return extrude_z(Tree(t), Tree(zmin), Tree(zmax)).release();
}
////////////////////////////////////////////////////////////////////////////////
// transforms
LIBFIVE_STDLIB move(libfive_tree t, tvec3 offset) {
    return move(Tree(t), TreeVec3{Tree(offset.x), Tree(offset.y), Tree(offset.z)}).release();
}
LIBFIVE_STDLIB rotate_z(libfive_tree t, libfive_float angle, tvec3 center) {
    return rotate_z(Tree(t), Tree(angle), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB taper_xy_z(libfive_tree shape, tvec3 base, libfive_float height, libfive_float scale, libfive_float base_scale) {
    return taper_xy_z(Tree(shape), TreeVec3{Tree(base.x), Tree(base.y), Tree(base.z)}, Tree(height), Tree(scale), Tree(base_scale)).release();
}
