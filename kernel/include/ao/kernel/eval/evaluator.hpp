/*
 *  Copyright (C) 2016 Matthew Keeter  <matt.j.keeter@gmail.com>
 *
 *  This file is part of the Ao library.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  Ao is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Ao.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <array>
#include <unordered_map>
#include <vector>

#include <glm/mat4x4.hpp>

#include "ao/kernel/eval/row.hpp"
#include "ao/kernel/eval/interval.hpp"
#include "ao/kernel/eval/clause.hpp"

////////////////////////////////////////////////////////////////////////////////

class Atom;
class Clause;
class Tree;

class Evaluator
{
public:
    /*
     *  Construct an evaluator for the given tree
     */
    explicit Evaluator(const Tree* t);
    explicit Evaluator(const Tree* t, const glm::mat4& m);
    ~Evaluator();

    /*
     *  Sets the matrix constants to the given matrix
     */
    void setMatrix(const glm::mat4& m);

    /*
     *  Single-argument evaluation
     */
    float eval(float x, float y, float z);
    Interval eval(Interval x, Interval y, Interval z);

    /*
     *  Evaluates a set of floating-point results
     *  (which have been loaded with set)
     */
#ifdef __AVX__
    const float* values(size_t count, bool vectorize=true);
#else
    const float* values(size_t count);
#endif

    /*
     *  Evaluate a set of gradients, returning a tuple
     *      value, dx, dy, dz
     *
     *  Values must have been previously loaded by set
     */
#ifdef __AVX__
    std::tuple<const float*, const float*,
               const float*, const float*> derivs(size_t count,
                                                  bool vectorize=true);
#else
    std::tuple<const float*, const float*,
               const float*, const float*> derivs(size_t count);
#endif

    /*
     *  Evaluates a single interval (stored with set)
     */
    Interval interval();

    /*
     *  Stores the given value in the result arrays
     *  (inlined for efficiency)
     */
    void set(float x, float y, float z, size_t index)
    {
        X->result.set(x, index);
        Y->result.set(y, index);
        Z->result.set(z, index);
    }

    /*
     *  Stores the given interval in the result objects
     */
    void set(Interval X, Interval Y, Interval Z);

    /*
     *  Pushes into a subinterval, disabling inactive nodes
     */
    void push();

    /*
     *  Pops out of interval evaluation, re-enabling disabled nodes
     */
    void pop();

    /*
     *  Returns the fraction active / total nodes
     *  (to check how well disabling is working)
     */
    double utilization() const;

protected:
    /*  All operations live in a set of rows sorted by weight */
    std::vector<Row> rows;

    /*  Our position variables are stored as separate pointers     *
     *  (so that they can be easily accessed to set their values)  */
    Clause *X, *Y, *Z;

    /*  matrices storea bunch of AFFINE_ROOT clauses and their constant values
     *  This list is used to apply a 4x4 transform matrix across the tree  */
    std::vector<std::pair<Clause*, glm::vec4>> matrices;

    /*  Pointers to constants live in this vector  */
    std::vector<Clause*> constants;

    /*  This is the top atom of the tree  */
    Clause* root;

    /*  Bag-o-data that stores clauses  */
    Clause* data;
};
