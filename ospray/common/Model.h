// ======================================================================== //
// Copyright 2009-2015 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

// ospray stuff
#include "ospray/geometry/Geometry.h"
#include "ospray/volume/Volume.h"

// stl stuff
#include <vector>

// embree stuff
#include "embree2/rtcore.h"
#include "embree2/rtcore_scene.h"
#include "embree2/rtcore_geometry.h"

namespace ospray {

  /*! \brief Base Abstraction for an OSPRay 'Model' entity

    A 'model' is the generalization of a 'scene' in embree: it is a
    collection of geometries and volumes that one can trace rays
    against, and that one can afterwards 'query' for certain
    properties (like the shading normal or material for a given
    ray/model intersection) */
  struct Model : public ManagedObject
  {
    Model();

    //! \brief common function to help printf-debugging 
    virtual std::string toString() const { return "ospray::Model"; }
    virtual void finalize();

    typedef std::vector<Ref<Geometry> > GeometryVector;
    GeometryVector geometry;

    std::vector<Ref<Volume> > volumes;

    box3f bounds;

    //! \brief the embree scene handle for this geometry
    RTCScene embreeSceneHandle; 
  };

} // ::ospray
