#|
Guile bindings to the libfive CAD kernel

DO NOT EDIT BY HAND!
This file is automatically generated from libfive/stdlib/stdlib.h

It was last generated on 2021-02-20 13:49:53 by user mkeeter
|#

(define-module (libfive stdlib shapes))
(use-modules (system foreign) (libfive lib) (libfive kernel) (libfive vec))

(define ffi_circle (pointer->procedure '*
  (dynamic-func "circle" stdlib)
  (list '* (list '* '*))))
(define* (circle r #:optional (center #[0 0]))
  " A 2D circle with the given radius and optional center"
  (ptr->shape (ffi_circle
    (shape->ptr (ensure-shape r))
    (vec2->tvec2 center))))
(export circle)

(define ffi_ring (pointer->procedure '*
  (dynamic-func "ring" stdlib)
  (list '* '* (list '* '*))))
(define* (ring ro ri #:optional (center #[0 0]))
  " A 2D ring with the given outer/inner radii and optional center"
  (ptr->shape (ffi_ring
    (shape->ptr (ensure-shape ro))
    (shape->ptr (ensure-shape ri))
    (vec2->tvec2 center))))
(export ring)

(define ffi_polygon (pointer->procedure '*
  (dynamic-func "polygon" stdlib)
  (list '* int (list '* '*))))
(define* (polygon r n #:optional (center #[0 0]))
  " A polygon with center-to-vertex distance r and n sides"
  (ptr->shape (ffi_polygon
    (shape->ptr (ensure-shape r))
    n
    (vec2->tvec2 center))))
(export polygon)

(define ffi_rectangle (pointer->procedure '*
  (dynamic-func "rectangle" stdlib)
  (list (list '* '*) (list '* '*))))
(define* (rectangle a b)
  " A rectangle with the given bounding corners"
  (ptr->shape (ffi_rectangle
    (vec2->tvec2 a)
    (vec2->tvec2 b))))
(export rectangle)

(define ffi_rounded-rectangle (pointer->procedure '*
  (dynamic-func "rounded_rectangle" stdlib)
  (list (list '* '*) (list '* '*) '*)))
(define* (rounded-rectangle a b r)
  " A rectangle with rounded corners"
  (ptr->shape (ffi_rounded-rectangle
    (vec2->tvec2 a)
    (vec2->tvec2 b)
    (shape->ptr (ensure-shape r)))))
(export rounded-rectangle)

(define ffi_rectangle-exact (pointer->procedure '*
  (dynamic-func "rectangle_exact" stdlib)
  (list (list '* '*) (list '* '*))))
(define* (rectangle-exact a b)
  " A rectangle from an exact distance field"
  (ptr->shape (ffi_rectangle-exact
    (vec2->tvec2 a)
    (vec2->tvec2 b))))
(export rectangle-exact)

(define ffi_rectangle-centered-exact (pointer->procedure '*
  (dynamic-func "rectangle_centered_exact" stdlib)
  (list (list '* '*) (list '* '*))))
(define* (rectangle-centered-exact size #:optional (center #[0 0]))
  " An exact-field rectangle at the (optional) center"
  (ptr->shape (ffi_rectangle-centered-exact
    (vec2->tvec2 size)
    (vec2->tvec2 center))))
(export rectangle-centered-exact)

(define ffi_triangle (pointer->procedure '*
  (dynamic-func "triangle" stdlib)
  (list (list '* '*) (list '* '*) (list '* '*))))
(define* (triangle a b c)
  " A 2D triangle"
  (ptr->shape (ffi_triangle
    (vec2->tvec2 a)
    (vec2->tvec2 b)
    (vec2->tvec2 c))))
(export triangle)

(define ffi_box-mitered (pointer->procedure '*
  (dynamic-func "box_mitered" stdlib)
  (list (list '* '* '*) (list '* '* '*))))
(define* (box-mitered a b)
  " A box with the given bounds, which will stay creased if offset"
  (ptr->shape (ffi_box-mitered
    (vec3->tvec3 a)
    (vec3->tvec3 b))))
(export box-mitered)

(define ffi_box-mitered-centered (pointer->procedure '*
  (dynamic-func "box_mitered_centered" stdlib)
  (list (list '* '* '*) (list '* '* '*))))
(define* (box-mitered-centered size #:optional (center #[0 0 0]))
  " A box with the given size and (optional) center, with edges that
  will stay sharp if offset."
  (ptr->shape (ffi_box-mitered-centered
    (vec3->tvec3 size)
    (vec3->tvec3 center))))
(export box-mitered-centered)

(define ffi_box-exact-centered (pointer->procedure '*
  (dynamic-func "box_exact_centered" stdlib)
  (list (list '* '* '*) (list '* '* '*))))
(define* (box-exact-centered size #:optional (center #[0 0 0]))
  " A box with the given size, centered around the given point,
  with a Euclidean distance metric"
  (ptr->shape (ffi_box-exact-centered
    (vec3->tvec3 size)
    (vec3->tvec3 center))))
(export box-exact-centered)

(define ffi_box-exact (pointer->procedure '*
  (dynamic-func "box_exact" stdlib)
  (list (list '* '* '*) (list '* '* '*))))
(define* (box-exact a b)
  " A box with the given bounds with a Euclidean distance metric"
  (ptr->shape (ffi_box-exact
    (vec3->tvec3 a)
    (vec3->tvec3 b))))
(export box-exact)

(define ffi_box-rounded (pointer->procedure '*
  (dynamic-func "box_rounded" stdlib)
  (list (list '* '* '*) (list '* '* '*) '*)))
(define* (box-rounded a b r)
  " Rounded box with the given bounds and radius (as a 0-1 fraction)"
  (ptr->shape (ffi_box-rounded
    (vec3->tvec3 a)
    (vec3->tvec3 b)
    (shape->ptr (ensure-shape r)))))
(export box-rounded)

(define ffi_sphere (pointer->procedure '*
  (dynamic-func "sphere" stdlib)
  (list '* (list '* '* '*))))
(define* (sphere radius #:optional (center #[0 0 0]))
  " A sphere with the given radius and (optional) center"
  (ptr->shape (ffi_sphere
    (shape->ptr (ensure-shape radius))
    (vec3->tvec3 center))))
(export sphere)

(define ffi_half-space (pointer->procedure '*
  (dynamic-func "half_space" stdlib)
  (list (list '* '* '*) (list '* '* '*))))
(define* (half-space norm #:optional (point #[0 0 0]))
  " A plane which divides the world into inside and outside, defined by its
  normal and a single point on the plane"
  (ptr->shape (ffi_half-space
    (vec3->tvec3 norm)
    (vec3->tvec3 point))))
(export half-space)

(define ffi_cylinder-z (pointer->procedure '*
  (dynamic-func "cylinder_z" stdlib)
  (list '* '* (list '* '* '*))))
(define* (cylinder-z r h #:optional (base #[0 0 0]))
  " A cylinder with the given radius and height, extruded from the
  (optional) base position."
  (ptr->shape (ffi_cylinder-z
    (shape->ptr (ensure-shape r))
    (shape->ptr (ensure-shape h))
    (vec3->tvec3 base))))
(export cylinder-z)

(define ffi_cone-ang-z (pointer->procedure '*
  (dynamic-func "cone_ang_z" stdlib)
  (list '* '* (list '* '* '*))))
(define* (cone-ang-z angle height #:optional (base #[0 0 0]))
  " A cone defined by its slope angle, height, and (optional) base location"
  (ptr->shape (ffi_cone-ang-z
    (shape->ptr (ensure-shape angle))
    (shape->ptr (ensure-shape height))
    (vec3->tvec3 base))))
(export cone-ang-z)

(define ffi_cone-z (pointer->procedure '*
  (dynamic-func "cone_z" stdlib)
  (list '* '* (list '* '* '*))))
(define* (cone-z radius height #:optional (base #[0 0 0]))
  " A cone defined by its radius, height, and (optional) base location"
  (ptr->shape (ffi_cone-z
    (shape->ptr (ensure-shape radius))
    (shape->ptr (ensure-shape height))
    (vec3->tvec3 base))))
(export cone-z)

(define ffi_pyramid-z (pointer->procedure '*
  (dynamic-func "pyramid_z" stdlib)
  (list (list '* '*) (list '* '*) '* '*)))
(define* (pyramid-z a b zmin height)
  " A pyramid defined by its base rectangle, lower Z value, and height"
  (ptr->shape (ffi_pyramid-z
    (vec2->tvec2 a)
    (vec2->tvec2 b)
    (shape->ptr (ensure-shape zmin))
    (shape->ptr (ensure-shape height)))))
(export pyramid-z)

(define ffi_torus-z (pointer->procedure '*
  (dynamic-func "torus_z" stdlib)
  (list '* '* (list '* '* '*))))
(define* (torus-z ro ri #:optional (center #[0 0 0]))
  " A torus with the given outer radius, inner radius, and (optional) center"
  (ptr->shape (ffi_torus-z
    (shape->ptr (ensure-shape ro))
    (shape->ptr (ensure-shape ri))
    (vec3->tvec3 center))))
(export torus-z)

(define ffi_gyroid (pointer->procedure '*
  (dynamic-func "gyroid" stdlib)
  (list (list '* '* '*) '*)))
(define* (gyroid period thickness)
  " A volume-filling gyroid with the given periods and thickness"
  (ptr->shape (ffi_gyroid
    (vec3->tvec3 period)
    (shape->ptr (ensure-shape thickness)))))
(export gyroid)

(define ffi_array-x (pointer->procedure '*
  (dynamic-func "array_x" stdlib)
  (list '* int '*)))
(define* (array-x shape nx dx)
  " Iterates a part in a 1D array"
  (ptr->shape (ffi_array-x
    (shape->ptr (ensure-shape shape))
    nx
    (shape->ptr (ensure-shape dx)))))
(export array-x)

(define ffi_array-xy (pointer->procedure '*
  (dynamic-func "array_xy" stdlib)
  (list '* int int (list '* '*))))
(define* (array-xy shape nx ny delta)
  " Iterates a part in a 2D array"
  (ptr->shape (ffi_array-xy
    (shape->ptr (ensure-shape shape))
    nx
    ny
    (vec2->tvec2 delta))))
(export array-xy)

(define ffi_array-xyz (pointer->procedure '*
  (dynamic-func "array_xyz" stdlib)
  (list '* int int int (list '* '* '*))))
(define* (array-xyz shape nx ny nz delta)
  " Iterates a part in a 3D array"
  (ptr->shape (ffi_array-xyz
    (shape->ptr (ensure-shape shape))
    nx
    ny
    nz
    (vec3->tvec3 delta))))
(export array-xyz)

(define ffi_array-polar-z (pointer->procedure '*
  (dynamic-func "array_polar_z" stdlib)
  (list '* int (list '* '*))))
(define* (array-polar-z shape n #:optional (center #[0 0]))
  " Iterates a shape about an optional center position"
  (ptr->shape (ffi_array-polar-z
    (shape->ptr (ensure-shape shape))
    n
    (vec2->tvec2 center))))
(export array-polar-z)

(define ffi_extrude-z (pointer->procedure '*
  (dynamic-func "extrude_z" stdlib)
  (list '* '* '*)))
(define* (extrude-z t zmin zmax)
  " Extrudes a 2D shape between zmin and zmax"
  (ptr->shape (ffi_extrude-z
    (shape->ptr (ensure-shape t))
    (shape->ptr (ensure-shape zmin))
    (shape->ptr (ensure-shape zmax)))))
(export extrude-z)
