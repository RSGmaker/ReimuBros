#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ManifoldType
#include <box2D/collision/B2ManifoldType.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraint
#include <box2D/dynamics/contacts/B2ContactConstraint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint
#include <box2D/dynamics/contacts/B2ContactConstraintPoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2PositionSolverManifold
#include <box2D/dynamics/contacts/B2PositionSolverManifold.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2PositionSolverManifold_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2PositionSolverManifold","new",0x0dc68ee0,"box2D.dynamics.contacts.B2PositionSolverManifold.new","box2D/dynamics/contacts/B2PositionSolverManifold.hx",32,0x2c65300f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(33)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->m_normal = _g;
	HX_STACK_LINE(34)
	Array< Float > _g1 = Array_obj< Float >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(34)
	this->m_separations = _g1;
	HX_STACK_LINE(35)
	Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(35)
	this->m_points = _g2;
	HX_STACK_LINE(36)
	{
		HX_STACK_LINE(36)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(36)
		int _g3 = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(36)
		while((true)){
			HX_STACK_LINE(36)
			if ((!(((_g11 < _g3))))){
				HX_STACK_LINE(36)
				break;
			}
			HX_STACK_LINE(36)
			int i = (_g11)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(38)
			this->m_points[i] = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
}
;
	return null();
}

//B2PositionSolverManifold_obj::~B2PositionSolverManifold_obj() { }

Dynamic B2PositionSolverManifold_obj::__CreateEmpty() { return  new B2PositionSolverManifold_obj; }
hx::ObjectPtr< B2PositionSolverManifold_obj > B2PositionSolverManifold_obj::__new()
{  hx::ObjectPtr< B2PositionSolverManifold_obj > result = new B2PositionSolverManifold_obj();
	result->__construct();
	return result;}

Dynamic B2PositionSolverManifold_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PositionSolverManifold_obj > result = new B2PositionSolverManifold_obj();
	result->__construct();
	return result;}

Void B2PositionSolverManifold_obj::initialize( ::box2D::dynamics::contacts::B2ContactConstraint cc){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2PositionSolverManifold","initialize",0x5b7542d0,"box2D.dynamics.contacts.B2PositionSolverManifold.initialize","box2D/dynamics/contacts/B2PositionSolverManifold.hx",45,0x2c65300f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cc,"cc")
		HX_STACK_LINE(46)
		::box2D::common::B2Settings_obj::b2Assert((cc->pointCount > (int)0));
		HX_STACK_LINE(48)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(49)
		Float clipPointX;		HX_STACK_VAR(clipPointX,"clipPointX");
		HX_STACK_LINE(50)
		Float clipPointY;		HX_STACK_VAR(clipPointY,"clipPointY");
		HX_STACK_LINE(51)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(52)
		::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(53)
		Float planePointX;		HX_STACK_VAR(planePointX,"planePointX");
		HX_STACK_LINE(54)
		Float planePointY;		HX_STACK_VAR(planePointY,"planePointY");
		HX_STACK_LINE(56)
		{
			HX_STACK_LINE(56)
			::box2D::collision::B2ManifoldType _g = cc->type;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(56)
			switch( (int)(_g->__Index())){
				case (int)0: {
					HX_STACK_LINE(61)
					tMat = cc->bodyA->m_xf->R;
					HX_STACK_LINE(62)
					tVec = cc->localPoint;
					HX_STACK_LINE(63)
					Float pointAX = (cc->bodyA->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(pointAX,"pointAX");
					HX_STACK_LINE(64)
					Float pointAY = (cc->bodyA->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(pointAY,"pointAY");
					HX_STACK_LINE(66)
					tMat = cc->bodyB->m_xf->R;
					HX_STACK_LINE(67)
					tVec = cc->points->__get((int)0).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >()->localPoint;
					HX_STACK_LINE(68)
					Float pointBX = (cc->bodyB->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(pointBX,"pointBX");
					HX_STACK_LINE(69)
					Float pointBY = (cc->bodyB->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(pointBY,"pointBY");
					HX_STACK_LINE(70)
					Float dX = (pointBX - pointAX);		HX_STACK_VAR(dX,"dX");
					HX_STACK_LINE(71)
					Float dY = (pointBY - pointAY);		HX_STACK_VAR(dY,"dY");
					HX_STACK_LINE(72)
					Float d2 = ((dX * dX) + (dY * dY));		HX_STACK_VAR(d2,"d2");
					HX_STACK_LINE(73)
					if (((d2 > 0.))){
						HX_STACK_LINE(75)
						Float d = ::Math_obj::sqrt(d2);		HX_STACK_VAR(d,"d");
						HX_STACK_LINE(76)
						this->m_normal->x = (Float(dX) / Float(d));
						HX_STACK_LINE(77)
						this->m_normal->y = (Float(dY) / Float(d));
					}
					else{
						HX_STACK_LINE(81)
						this->m_normal->x = 1.0;
						HX_STACK_LINE(82)
						this->m_normal->y = 0.0;
					}
					HX_STACK_LINE(84)
					this->m_points->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x = (0.5 * ((pointAX + pointBX)));
					HX_STACK_LINE(85)
					this->m_points->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y = (0.5 * ((pointAY + pointBY)));
					HX_STACK_LINE(86)
					this->m_separations[(int)0] = (((dX * this->m_normal->x) + (dY * this->m_normal->y)) - cc->radius);
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(92)
					tMat = cc->bodyA->m_xf->R;
					HX_STACK_LINE(93)
					tVec = cc->localPlaneNormal;
					HX_STACK_LINE(94)
					this->m_normal->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
					HX_STACK_LINE(95)
					this->m_normal->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
					HX_STACK_LINE(97)
					tMat = cc->bodyA->m_xf->R;
					HX_STACK_LINE(98)
					tVec = cc->localPoint;
					HX_STACK_LINE(99)
					planePointX = (cc->bodyA->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
					HX_STACK_LINE(100)
					planePointY = (cc->bodyA->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
					HX_STACK_LINE(102)
					tMat = cc->bodyB->m_xf->R;
					HX_STACK_LINE(103)
					{
						HX_STACK_LINE(103)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(103)
						int _g1 = cc->pointCount;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(103)
						while((true)){
							HX_STACK_LINE(103)
							if ((!(((_g2 < _g1))))){
								HX_STACK_LINE(103)
								break;
							}
							HX_STACK_LINE(103)
							int i1 = (_g2)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(106)
							tVec = cc->points->__get(i1).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >()->localPoint;
							HX_STACK_LINE(107)
							clipPointX = (cc->bodyB->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
							HX_STACK_LINE(108)
							clipPointY = (cc->bodyB->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
							HX_STACK_LINE(109)
							this->m_separations[i1] = (((((clipPointX - planePointX)) * this->m_normal->x) + (((clipPointY - planePointY)) * this->m_normal->y)) - cc->radius);
							HX_STACK_LINE(110)
							this->m_points->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->x = clipPointX;
							HX_STACK_LINE(111)
							this->m_points->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->y = clipPointY;
						}
					}
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(118)
					tMat = cc->bodyB->m_xf->R;
					HX_STACK_LINE(119)
					tVec = cc->localPlaneNormal;
					HX_STACK_LINE(120)
					this->m_normal->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
					HX_STACK_LINE(121)
					this->m_normal->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
					HX_STACK_LINE(123)
					tMat = cc->bodyB->m_xf->R;
					HX_STACK_LINE(124)
					tVec = cc->localPoint;
					HX_STACK_LINE(125)
					planePointX = (cc->bodyB->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
					HX_STACK_LINE(126)
					planePointY = (cc->bodyB->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
					HX_STACK_LINE(128)
					tMat = cc->bodyA->m_xf->R;
					HX_STACK_LINE(129)
					{
						HX_STACK_LINE(129)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(129)
						int _g1 = cc->pointCount;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(129)
						while((true)){
							HX_STACK_LINE(129)
							if ((!(((_g2 < _g1))))){
								HX_STACK_LINE(129)
								break;
							}
							HX_STACK_LINE(129)
							int i1 = (_g2)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(132)
							tVec = cc->points->__get(i1).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >()->localPoint;
							HX_STACK_LINE(133)
							clipPointX = (cc->bodyA->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
							HX_STACK_LINE(134)
							clipPointY = (cc->bodyA->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
							HX_STACK_LINE(135)
							this->m_separations[i1] = (((((clipPointX - planePointX)) * this->m_normal->x) + (((clipPointY - planePointY)) * this->m_normal->y)) - cc->radius);
							HX_STACK_LINE(136)
							this->m_points->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->set(clipPointX,clipPointY);
						}
					}
					HX_STACK_LINE(140)
					hx::MultEq(this->m_normal->x,(int)-1);
					HX_STACK_LINE(141)
					hx::MultEq(this->m_normal->y,(int)-1);
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PositionSolverManifold_obj,initialize,(void))

::box2D::common::math::B2Vec2 B2PositionSolverManifold_obj::circlePointA;

::box2D::common::math::B2Vec2 B2PositionSolverManifold_obj::circlePointB;


B2PositionSolverManifold_obj::B2PositionSolverManifold_obj()
{
}

void B2PositionSolverManifold_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PositionSolverManifold);
	HX_MARK_MEMBER_NAME(m_normal,"m_normal");
	HX_MARK_MEMBER_NAME(m_points,"m_points");
	HX_MARK_MEMBER_NAME(m_separations,"m_separations");
	HX_MARK_END_CLASS();
}

void B2PositionSolverManifold_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_normal,"m_normal");
	HX_VISIT_MEMBER_NAME(m_points,"m_points");
	HX_VISIT_MEMBER_NAME(m_separations,"m_separations");
}

Dynamic B2PositionSolverManifold_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_normal") ) { return m_normal; }
		if (HX_FIELD_EQ(inName,"m_points") ) { return m_points; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"circlePointA") ) { return circlePointA; }
		if (HX_FIELD_EQ(inName,"circlePointB") ) { return circlePointB; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_separations") ) { return m_separations; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2PositionSolverManifold_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_normal") ) { m_normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_points") ) { m_points=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"circlePointA") ) { circlePointA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"circlePointB") ) { circlePointB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_separations") ) { m_separations=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2PositionSolverManifold_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_normal"));
	outFields->push(HX_CSTRING("m_points"));
	outFields->push(HX_CSTRING("m_separations"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("circlePointA"),
	HX_CSTRING("circlePointB"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PositionSolverManifold_obj,m_normal),HX_CSTRING("m_normal")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2PositionSolverManifold_obj,m_points),HX_CSTRING("m_points")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(B2PositionSolverManifold_obj,m_separations),HX_CSTRING("m_separations")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("m_normal"),
	HX_CSTRING("m_points"),
	HX_CSTRING("m_separations"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2PositionSolverManifold_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2PositionSolverManifold_obj::circlePointA,"circlePointA");
	HX_MARK_MEMBER_NAME(B2PositionSolverManifold_obj::circlePointB,"circlePointB");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2PositionSolverManifold_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2PositionSolverManifold_obj::circlePointA,"circlePointA");
	HX_VISIT_MEMBER_NAME(B2PositionSolverManifold_obj::circlePointB,"circlePointB");
};

#endif

Class B2PositionSolverManifold_obj::__mClass;

void B2PositionSolverManifold_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2PositionSolverManifold"), hx::TCanCast< B2PositionSolverManifold_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void B2PositionSolverManifold_obj::__boot()
{
	circlePointA= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	circlePointB= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
