#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#include <box2D/collision/B2ManifoldPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldType
#include <box2D/collision/B2ManifoldType.h>
#endif
#ifndef INCLUDED_box2D_collision_B2WorldManifold
#include <box2D/collision/B2WorldManifold.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace collision{

Void B2WorldManifold_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2WorldManifold","new",0xc10e5117,"box2D.collision.B2WorldManifold.new","box2D/collision/B2WorldManifold.hx",35,0xa4b501fb)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(36)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(36)
	this->m_normal = _g;
	HX_STACK_LINE(38)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(38)
	this->m_points = _g1;
	HX_STACK_LINE(39)
	{
		HX_STACK_LINE(39)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(39)
		int _g2 = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(39)
		while((true)){
			HX_STACK_LINE(39)
			if ((!(((_g11 < _g2))))){
				HX_STACK_LINE(39)
				break;
			}
			HX_STACK_LINE(39)
			int i = (_g11)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(41)
			this->m_points[i] = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
}
;
	return null();
}

//B2WorldManifold_obj::~B2WorldManifold_obj() { }

Dynamic B2WorldManifold_obj::__CreateEmpty() { return  new B2WorldManifold_obj; }
hx::ObjectPtr< B2WorldManifold_obj > B2WorldManifold_obj::__new()
{  hx::ObjectPtr< B2WorldManifold_obj > result = new B2WorldManifold_obj();
	result->__construct();
	return result;}

Dynamic B2WorldManifold_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2WorldManifold_obj > result = new B2WorldManifold_obj();
	result->__construct();
	return result;}

Void B2WorldManifold_obj::initialize( ::box2D::collision::B2Manifold manifold,::box2D::common::math::B2Transform xfA,Float radiusA,::box2D::common::math::B2Transform xfB,Float radiusB){
{
		HX_STACK_FRAME("box2D.collision.B2WorldManifold","initialize",0x33604579,"box2D.collision.B2WorldManifold.initialize","box2D/collision/B2WorldManifold.hx",53,0xa4b501fb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(manifold,"manifold")
		HX_STACK_ARG(xfA,"xfA")
		HX_STACK_ARG(radiusA,"radiusA")
		HX_STACK_ARG(xfB,"xfB")
		HX_STACK_ARG(radiusB,"radiusB")
		HX_STACK_LINE(54)
		if (((manifold->m_pointCount == (int)0))){
			HX_STACK_LINE(56)
			return null();
		}
		HX_STACK_LINE(59)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(60)
		::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(61)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(62)
		Float normalX;		HX_STACK_VAR(normalX,"normalX");
		HX_STACK_LINE(63)
		Float normalY;		HX_STACK_VAR(normalY,"normalY");
		HX_STACK_LINE(64)
		Float planePointX;		HX_STACK_VAR(planePointX,"planePointX");
		HX_STACK_LINE(65)
		Float planePointY;		HX_STACK_VAR(planePointY,"planePointY");
		HX_STACK_LINE(66)
		Float clipPointX;		HX_STACK_VAR(clipPointX,"clipPointX");
		HX_STACK_LINE(67)
		Float clipPointY;		HX_STACK_VAR(clipPointY,"clipPointY");
		HX_STACK_LINE(69)
		{
			HX_STACK_LINE(69)
			::box2D::collision::B2ManifoldType _g = manifold->m_type;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(69)
			switch( (int)(_g->__Index())){
				case (int)0: {
					HX_STACK_LINE(74)
					tMat = xfA->R;
					HX_STACK_LINE(75)
					tVec = manifold->m_localPoint;
					HX_STACK_LINE(76)
					Float pointAX = ((xfA->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));		HX_STACK_VAR(pointAX,"pointAX");
					HX_STACK_LINE(77)
					Float pointAY = ((xfA->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));		HX_STACK_VAR(pointAY,"pointAY");
					HX_STACK_LINE(79)
					tMat = xfB->R;
					HX_STACK_LINE(80)
					tVec = manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_localPoint;
					HX_STACK_LINE(81)
					Float pointBX = ((xfB->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));		HX_STACK_VAR(pointBX,"pointBX");
					HX_STACK_LINE(82)
					Float pointBY = ((xfB->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));		HX_STACK_VAR(pointBY,"pointBY");
					HX_STACK_LINE(84)
					Float dX = (pointBX - pointAX);		HX_STACK_VAR(dX,"dX");
					HX_STACK_LINE(85)
					Float dY = (pointBY - pointAY);		HX_STACK_VAR(dY,"dY");
					HX_STACK_LINE(86)
					Float d2 = ((dX * dX) + (dY * dY));		HX_STACK_VAR(d2,"d2");
					HX_STACK_LINE(87)
					if (((d2 > 0.))){
						HX_STACK_LINE(89)
						Float d = ::Math_obj::sqrt(d2);		HX_STACK_VAR(d,"d");
						HX_STACK_LINE(90)
						this->m_normal->x = (Float(dX) / Float(d));
						HX_STACK_LINE(91)
						this->m_normal->y = (Float(dY) / Float(d));
					}
					else{
						HX_STACK_LINE(93)
						this->m_normal->x = (int)1;
						HX_STACK_LINE(94)
						this->m_normal->y = (int)0;
					}
					HX_STACK_LINE(98)
					Float cAX = (pointAX + (radiusA * this->m_normal->x));		HX_STACK_VAR(cAX,"cAX");
					HX_STACK_LINE(99)
					Float cAY = (pointAY + (radiusA * this->m_normal->y));		HX_STACK_VAR(cAY,"cAY");
					HX_STACK_LINE(101)
					Float cBX = (pointBX - (radiusB * this->m_normal->x));		HX_STACK_VAR(cBX,"cBX");
					HX_STACK_LINE(102)
					Float cBY = (pointBY - (radiusB * this->m_normal->y));		HX_STACK_VAR(cBY,"cBY");
					HX_STACK_LINE(103)
					this->m_points->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x = (0.5 * ((cAX + cBX)));
					HX_STACK_LINE(104)
					this->m_points->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y = (0.5 * ((cAY + cBY)));
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(110)
					tMat = xfA->R;
					HX_STACK_LINE(111)
					tVec = manifold->m_localPlaneNormal;
					HX_STACK_LINE(112)
					normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
					HX_STACK_LINE(113)
					normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
					HX_STACK_LINE(116)
					tMat = xfA->R;
					HX_STACK_LINE(117)
					tVec = manifold->m_localPoint;
					HX_STACK_LINE(118)
					planePointX = ((xfA->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
					HX_STACK_LINE(119)
					planePointY = ((xfA->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
					HX_STACK_LINE(122)
					this->m_normal->x = normalX;
					HX_STACK_LINE(123)
					this->m_normal->y = normalY;
					HX_STACK_LINE(124)
					{
						HX_STACK_LINE(124)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(124)
						int _g1 = manifold->m_pointCount;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(124)
						while((true)){
							HX_STACK_LINE(124)
							if ((!(((_g2 < _g1))))){
								HX_STACK_LINE(124)
								break;
							}
							HX_STACK_LINE(124)
							int i1 = (_g2)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(127)
							tMat = xfB->R;
							HX_STACK_LINE(128)
							tVec = manifold->m_points->__get(i1).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_localPoint;
							HX_STACK_LINE(129)
							clipPointX = ((xfB->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
							HX_STACK_LINE(130)
							clipPointY = ((xfB->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
							HX_STACK_LINE(135)
							this->m_points->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->x = (clipPointX + ((0.5 * ((((radiusA - (((clipPointX - planePointX)) * normalX)) - (((clipPointY - planePointY)) * normalY)) - radiusB))) * normalX));
							HX_STACK_LINE(136)
							this->m_points->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->y = (clipPointY + ((0.5 * ((((radiusA - (((clipPointX - planePointX)) * normalX)) - (((clipPointY - planePointY)) * normalY)) - radiusB))) * normalY));
						}
					}
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(144)
					tMat = xfB->R;
					HX_STACK_LINE(145)
					tVec = manifold->m_localPlaneNormal;
					HX_STACK_LINE(146)
					normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
					HX_STACK_LINE(147)
					normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
					HX_STACK_LINE(150)
					tMat = xfB->R;
					HX_STACK_LINE(151)
					tVec = manifold->m_localPoint;
					HX_STACK_LINE(152)
					planePointX = ((xfB->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
					HX_STACK_LINE(153)
					planePointY = ((xfB->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
					HX_STACK_LINE(156)
					this->m_normal->x = -(normalX);
					HX_STACK_LINE(157)
					this->m_normal->y = -(normalY);
					HX_STACK_LINE(158)
					{
						HX_STACK_LINE(158)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(158)
						int _g1 = manifold->m_pointCount;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(158)
						while((true)){
							HX_STACK_LINE(158)
							if ((!(((_g2 < _g1))))){
								HX_STACK_LINE(158)
								break;
							}
							HX_STACK_LINE(158)
							int i1 = (_g2)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(161)
							tMat = xfA->R;
							HX_STACK_LINE(162)
							tVec = manifold->m_points->__get(i1).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_localPoint;
							HX_STACK_LINE(163)
							clipPointX = ((xfA->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
							HX_STACK_LINE(164)
							clipPointY = ((xfA->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
							HX_STACK_LINE(169)
							this->m_points->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->x = (clipPointX + ((0.5 * ((((radiusB - (((clipPointX - planePointX)) * normalX)) - (((clipPointY - planePointY)) * normalY)) - radiusA))) * normalX));
							HX_STACK_LINE(170)
							this->m_points->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->y = (clipPointY + ((0.5 * ((((radiusB - (((clipPointX - planePointX)) * normalX)) - (((clipPointY - planePointY)) * normalY)) - radiusA))) * normalY));
						}
					}
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(B2WorldManifold_obj,initialize,(void))


B2WorldManifold_obj::B2WorldManifold_obj()
{
}

void B2WorldManifold_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2WorldManifold);
	HX_MARK_MEMBER_NAME(m_normal,"m_normal");
	HX_MARK_MEMBER_NAME(m_points,"m_points");
	HX_MARK_END_CLASS();
}

void B2WorldManifold_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_normal,"m_normal");
	HX_VISIT_MEMBER_NAME(m_points,"m_points");
}

Dynamic B2WorldManifold_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_normal") ) { return m_normal; }
		if (HX_FIELD_EQ(inName,"m_points") ) { return m_points; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2WorldManifold_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_normal") ) { m_normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_points") ) { m_points=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2WorldManifold_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_normal"));
	outFields->push(HX_CSTRING("m_points"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2WorldManifold_obj,m_normal),HX_CSTRING("m_normal")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2WorldManifold_obj,m_points),HX_CSTRING("m_points")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("m_normal"),
	HX_CSTRING("m_points"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2WorldManifold_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2WorldManifold_obj::__mClass,"__mClass");
};

#endif

Class B2WorldManifold_obj::__mClass;

void B2WorldManifold_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2WorldManifold"), hx::TCanCast< B2WorldManifold_obj> ,sStaticFields,sMemberFields,
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

void B2WorldManifold_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
