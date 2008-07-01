/*******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 beta 1       *
*                (c) 2006-2007 MGH, INRIA, USTL, UJF, CNRS                     *
*                                                                              *
* This library is free software; you can redistribute it and/or modify it      *
* under the terms of the GNU Lesser General Public License as published by the *
* Free Software Foundation; either version 2.1 of the License, or (at your     *
* option) any later version.                                                   *
*                                                                              *
* This library is distributed in the hope that it will be useful, but WITHOUT  *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License  *
* for more details.                                                            *
*                                                                              *
* You should have received a copy of the GNU Lesser General Public License     *
* along with this library; if not, write to the Free Software Foundation,      *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.           *
*                                                                              *
* Contact information: contact@sofa-framework.org                              *
*                                                                              *
* Authors: J. Allard, P-J. Bensoussan, S. Cotin, C. Duriez, H. Delingette,     *
* F. Faure, S. Fonteneau, L. Heigeas, C. Mendoza, M. Nesme, P. Neumann,        *
* and F. Poyer                                                                 *
*******************************************************************************/
#include <sofa/component/constraint/LinearMovementConstraint.inl>
#include <sofa/core/ObjectFactory.h>
#include <sofa/defaulttype/Vec3Types.h>
#include <sofa/defaulttype/RigidTypes.h>

#include <sofa/simulation/tree/GNode.h>
#include <sofa/component/mass/UniformMass.h>

namespace sofa
{

namespace component
{

namespace constraint
{

using namespace sofa::defaulttype;
using namespace sofa::helper;


//display specialisation for rigid types
#ifndef SOFA_FLOAT
template <>
void LinearMovementConstraint<Rigid3dTypes>::draw()
{
    const SetIndexArray & indices = m_indices.getValue().getArray();
    if (!getContext()->getShowBehaviorModels()) return;
    glDisable (GL_LIGHTING);
    glPointSize(10);
    glColor4f (1,0.5,0.5,1);
    glBegin (GL_LINES);
    for (unsigned int i=0 ; i<m_keyMovements.getValue().size()-1 ; i++)
    {
        for (SetIndexArray::const_iterator it = indices.begin(); it != indices.end(); ++it)
        {
            gl::glVertexT(x0[*it].getCenter()+m_keyMovements.getValue()[i].getVCenter());
            gl::glVertexT(x0[*it].getCenter()+m_keyMovements.getValue()[i+1].getVCenter());
        }
    }
    glEnd();
}
#endif
#ifndef SOFA_DOUBLE
template <>
void LinearMovementConstraint<Rigid3fTypes>::draw()
{
    const SetIndexArray & indices = m_indices.getValue().getArray();
    if (!getContext()->getShowBehaviorModels()) return;
    glDisable (GL_LIGHTING);
    glPointSize(10);
    glColor4f (1,0.5,0.5,1);
    glBegin (GL_LINES);
    for (unsigned int i=0 ; i<m_keyMovements.getValue().size()-1 ; i++)
    {
        for (SetIndexArray::const_iterator it = indices.begin(); it != indices.end(); ++it)
        {
            gl::glVertexT(x0[*it].getCenter()+m_keyMovements.getValue()[i].getVCenter());
            gl::glVertexT(x0[*it].getCenter()+m_keyMovements.getValue()[i+1].getVCenter());
        }
    }
    glEnd();
}
#endif

//declaration of the class, for the factory
SOFA_DECL_CLASS(LinearMovementConstraint)


int LinearMovementConstraintClass = core::RegisterObject("translate given particles")
#ifndef SOFA_FLOAT
        .add< LinearMovementConstraint<Vec3dTypes> >()
        .add< LinearMovementConstraint<Vec2dTypes> >()
        .add< LinearMovementConstraint<Vec1dTypes> >()
        .add< LinearMovementConstraint<Vec6dTypes> >()
        .add< LinearMovementConstraint<Rigid3dTypes> >()
#endif
#ifndef SOFA_DOUBLE
        .add< LinearMovementConstraint<Vec3fTypes> >()
        .add< LinearMovementConstraint<Vec2fTypes> >()
        .add< LinearMovementConstraint<Vec1fTypes> >()
        .add< LinearMovementConstraint<Vec6fTypes> >()
        .add< LinearMovementConstraint<Rigid3fTypes> >()
#endif
        ;

#ifndef SOFA_FLOAT
template class LinearMovementConstraint<Vec3dTypes>;
template class LinearMovementConstraint<Vec2dTypes>;
template class LinearMovementConstraint<Vec1dTypes>;
template class LinearMovementConstraint<Vec6dTypes>;
template class LinearMovementConstraint<Rigid3dTypes>;
#endif
#ifndef SOFA_DOUBLE
template class LinearMovementConstraint<Vec3fTypes>;
template class LinearMovementConstraint<Vec2fTypes>;
template class LinearMovementConstraint<Vec1fTypes>;
template class LinearMovementConstraint<Vec6fTypes>;
template class LinearMovementConstraint<Rigid3fTypes>;
#endif

} // namespace constraint

} // namespace component

} // namespace sofa
