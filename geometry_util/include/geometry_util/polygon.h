// *****************************************************************************
//
// Copyright (c) 2014, Southwest Research Institute® (SwRI®)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the <organization> nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *****************************************************************************

#ifndef POLYGON_H_
#define POLYGON_H_

#include <sstream>

#ifndef DEG_TO_RAD
#define DEG_TO_RAD 0.0174532925
#endif

namespace geometry_util
{
  //structure for defining the vertices of a polygon
  typedef struct
  {
    //vertices
    double *x;
    double *y;
  }PolygonD;

  typedef struct
  {
    //vertex
    double x;
    double y;
  }Vertex;

  class Polygon{
  public:

    Polygon();
    Polygon(const Polygon & other);
    Polygon & operator= (const Polygon & other);

    Polygon(double Xs[], double Ys[], int numVertx);

    bool VertexInPolygon(Vertex vertex);

    double* GetXVerticies();

    double* GetYVerticies();

    double GetXVerticie(int num);

    double GetYVerticie(int num);

    int GetNumVerticies();

    bool LineOverlapsPolygon(Vertex start, Vertex end);

    ~Polygon();

  private:

    Vertex FindLineIntersectLine(Vertex start1, Vertex end1, Vertex start2,
        Vertex end2);

    PolygonD _shape;  //list of polygon vertices
    int _nvert;   //number of vertices in this polygon
  };
}  // end namespace geometry_util
#endif /* POLYGON_H_ */
