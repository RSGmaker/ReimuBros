#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_openfl__v2_Lib
#include <openfl/_v2/Lib.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_MovieClip
#include <openfl/_v2/display/MovieClip.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_Event
#include <openfl/_v2/events/Event.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_ByteArray
#include <openfl/_v2/utils/ByteArray.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_IDataInput
#include <openfl/_v2/utils/IDataInput.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_IDataOutput
#include <openfl/_v2/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_IMemoryRange
#include <openfl/_v2/utils/IMemoryRange.h>
#endif
#ifndef INCLUDED_openfl_errors_Error
#include <openfl/errors/Error.h>
#endif
#ifndef INCLUDED_openfl_errors_IOError
#include <openfl/errors/IOError.h>
#endif
#ifndef INCLUDED_openfl_errors_SecurityError
#include <openfl/errors/SecurityError.h>
#endif
#ifndef INCLUDED_openfl_events_ErrorEvent
#include <openfl/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_openfl_events_IOErrorEvent
#include <openfl/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_openfl_events_ProgressEvent
#include <openfl/events/ProgressEvent.h>
#endif
#ifndef INCLUDED_openfl_events_TextEvent
#include <openfl/events/TextEvent.h>
#endif
#ifndef INCLUDED_openfl_net_Socket
#include <openfl/net/Socket.h>
#endif
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
#ifndef INCLUDED_sys_net_Socket
#include <sys/net/Socket.h>
#endif
namespace openfl{
namespace net{

Void Socket_obj::__construct(::String host,hx::Null< int >  __o_port)
{
HX_STACK_FRAME("openfl.net.Socket","new",0xed4fa1d4,"openfl.net.Socket.new","openfl/net/Socket.hx",73,0x34d23f5a)
HX_STACK_THIS(this)
HX_STACK_ARG(host,"host")
HX_STACK_ARG(__o_port,"port")
int port = __o_port.Default(0);
{
	HX_STACK_LINE(74)
	super::__construct(null());
	HX_STACK_LINE(75)
	this->set_endian(HX_CSTRING("bigEndian"));
	HX_STACK_LINE(76)
	this->timeout = (int)20000;
	HX_STACK_LINE(77)
	::haxe::io::Bytes _g = ::haxe::io::Bytes_obj::alloc((int)4096);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(77)
	this->_buf = _g;
	HX_STACK_LINE(78)
	if (((bool((port > (int)0)) && bool((port < (int)65535))))){
		HX_STACK_LINE(79)
		this->connect(host,port);
	}
}
;
	return null();
}

//Socket_obj::~Socket_obj() { }

Dynamic Socket_obj::__CreateEmpty() { return  new Socket_obj; }
hx::ObjectPtr< Socket_obj > Socket_obj::__new(::String host,hx::Null< int >  __o_port)
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct(host,__o_port);
	return result;}

Dynamic Socket_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool Socket_obj::get_connected( ){
	HX_STACK_FRAME("openfl.net.Socket","get_connected",0x736e6114,"openfl.net.Socket.get_connected","openfl/net/Socket.hx",50,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(50)
	return this->_connected;
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,get_connected,return )

::String Socket_obj::get_endian( ){
	HX_STACK_FRAME("openfl.net.Socket","get_endian",0x7d7c0d70,"openfl.net.Socket.get_endian","openfl/net/Socket.hx",54,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(54)
	return this->endian;
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,get_endian,return )

::String Socket_obj::set_endian( ::String value){
	HX_STACK_FRAME("openfl.net.Socket","set_endian",0x80f9abe4,"openfl.net.Socket.set_endian","openfl/net/Socket.hx",57,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(58)
	this->endian = value;
	HX_STACK_LINE(59)
	if (((this->_input != null()))){
		HX_STACK_LINE(59)
		this->_input->set_endian(value);
	}
	HX_STACK_LINE(60)
	if (((this->_inputBuffer != null()))){
		HX_STACK_LINE(60)
		this->_inputBuffer->set_endian(value);
	}
	HX_STACK_LINE(61)
	if (((this->_output != null()))){
		HX_STACK_LINE(61)
		this->_output->set_endian(value);
	}
	HX_STACK_LINE(62)
	return this->get_endian();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,set_endian,return )

int Socket_obj::get_bytesAvailable( ){
	HX_STACK_FRAME("openfl.net.Socket","get_bytesAvailable",0xb0011db3,"openfl.net.Socket.get_bytesAvailable","openfl/net/Socket.hx",66,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(66)
	return this->_input->get_bytesAvailable();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,get_bytesAvailable,return )

int Socket_obj::get_bytesPending( ){
	HX_STACK_FRAME("openfl.net.Socket","get_bytesPending",0x28aaadc1,"openfl.net.Socket.get_bytesPending","openfl/net/Socket.hx",70,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(70)
	return this->_output->length;
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,get_bytesPending,return )

Void Socket_obj::connect( ::String host,Dynamic __o_port){
Dynamic port = __o_port.Default(0);
	HX_STACK_FRAME("openfl.net.Socket","connect",0x25b3d75e,"openfl.net.Socket.connect","openfl/net/Socket.hx",82,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(host,"host")
	HX_STACK_ARG(port,"port")
{
		HX_STACK_LINE(83)
		if (((this->_socket != null()))){
			HX_STACK_LINE(84)
			this->close();
		}
		HX_STACK_LINE(86)
		if (((bool((port < (int)0)) || bool((port > (int)65535))))){
			HX_STACK_LINE(87)
			HX_STACK_DO_THROW(::openfl::errors::SecurityError_obj::__new(HX_CSTRING("Invalid socket port number specified.")));
		}
		HX_STACK_LINE(92)
		::sys::net::Host h = null();		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(93)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(94)
			::sys::net::Host _g = ::sys::net::Host_obj::__new(host);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(94)
			h = _g;
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(96)
					::openfl::events::IOErrorEvent _g1 = ::openfl::events::IOErrorEvent_obj::__new(::openfl::events::IOErrorEvent_obj::IO_ERROR,true,false,HX_CSTRING("Invalid host"),null());		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(96)
					this->dispatchEvent(_g1);
					HX_STACK_LINE(97)
					return null();
				}
			}
		}
		HX_STACK_LINE(100)
		Float _g2 = ::Sys_obj::time();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(100)
		this->_stamp = _g2;
		HX_STACK_LINE(103)
		this->_host = host;
		HX_STACK_LINE(104)
		this->_port = port;
		HX_STACK_LINE(106)
		::openfl::_v2::utils::ByteArray _g3 = ::openfl::_v2::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(106)
		this->_output = _g3;
		HX_STACK_LINE(107)
		::String _g4 = this->get_endian();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(107)
		this->_output->set_endian(_g4);
		HX_STACK_LINE(108)
		::openfl::_v2::utils::ByteArray _g5 = ::openfl::_v2::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(108)
		this->_input = _g5;
		HX_STACK_LINE(109)
		::String _g6 = this->get_endian();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(109)
		this->_input->set_endian(_g6);
		HX_STACK_LINE(124)
		::sys::net::Socket _g7 = ::sys::net::Socket_obj::__new();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(124)
		this->_socket = _g7;
		HX_STACK_LINE(125)
		this->_socket->setBlocking(false);
		HX_STACK_LINE(126)
		this->_socket->setFastSend(true);
		HX_STACK_LINE(127)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(128)
			this->_socket->connect(h,port);
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
				}
			}
		}
		HX_STACK_LINE(133)
		::openfl::_v2::Lib_obj::get_current()->addEventListener(::openfl::_v2::events::Event_obj::ENTER_FRAME,this->onFrame_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,connect,(void))

Void Socket_obj::onFrame( Dynamic _){
{
		HX_STACK_FRAME("openfl.net.Socket","onFrame",0xacf4b202,"openfl.net.Socket.onFrame","openfl/net/Socket.hx",136,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(154)
		bool doConnect = false;		HX_STACK_VAR(doConnect,"doConnect");
		HX_STACK_LINE(155)
		bool doClose = false;		HX_STACK_VAR(doClose,"doClose");
		HX_STACK_LINE(157)
		if ((!(this->get_connected()))){
			HX_STACK_LINE(158)
			Dynamic r = ::sys::net::Socket_obj::select(null(),Array_obj< ::Dynamic >::__new().Add(this->_socket),null(),(int)0);		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(159)
			if (((r->__Field(HX_CSTRING("write"),true)->__GetItem((int)0) == this->_socket))){
				HX_STACK_LINE(160)
				doConnect = true;
			}
			else{
				HX_STACK_LINE(161)
				Float _g = ::Sys_obj::time();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(161)
				Float _g1 = (_g - this->_stamp);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(161)
				if (((_g1 > (Float(this->timeout) / Float((int)1000))))){
					HX_STACK_LINE(162)
					doClose = true;
				}
			}
		}
		HX_STACK_LINE(165)
		::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(166)
		int bLength = (int)0;		HX_STACK_VAR(bLength,"bLength");
		HX_STACK_LINE(167)
		if (((  ((!(this->get_connected()))) ? bool(doConnect) : bool(true) ))){
			HX_STACK_LINE(168)
			try
			{
			HX_STACK_CATCHABLE(::haxe::io::Error, 0);
			HX_STACK_CATCHABLE(Dynamic, 1);
			{
				HX_STACK_LINE(169)
				int l;		HX_STACK_VAR(l,"l");
				HX_STACK_LINE(170)
				while((true)){
					HX_STACK_LINE(171)
					int _g2 = this->_socket->input->readBytes(this->_buf,(int)0,this->_buf->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(171)
					l = _g2;
					HX_STACK_LINE(172)
					if (((l > (int)0))){
						HX_STACK_LINE(173)
						{
							HX_STACK_LINE(173)
							::haxe::io::Bytes src = this->_buf;		HX_STACK_VAR(src,"src");
							HX_STACK_LINE(173)
							if (((bool((l < (int)0)) || bool((l > src->length))))){
								HX_STACK_LINE(173)
								HX_STACK_DO_THROW(::haxe::io::Error_obj::OutsideBounds);
							}
							HX_STACK_LINE(173)
							Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
							HX_STACK_LINE(173)
							Array< unsigned char > b2 = src->b;		HX_STACK_VAR(b2,"b2");
							HX_STACK_LINE(173)
							{
								HX_STACK_LINE(173)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								HX_STACK_LINE(173)
								int _g = l;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(173)
								while((true)){
									HX_STACK_LINE(173)
									if ((!(((_g1 < _g))))){
										HX_STACK_LINE(173)
										break;
									}
									HX_STACK_LINE(173)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(173)
									b->b->push(b2->__get(i));
								}
							}
						}
						HX_STACK_LINE(174)
						hx::AddEq(bLength,l);
					}
					HX_STACK_LINE(170)
					if ((!(((l == this->_buf->length))))){
						HX_STACK_LINE(170)
						break;
					}
				}
			}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::haxe::io::Error >() ){
					HX_STACK_BEGIN_CATCH
					::haxe::io::Error e = __e;{
						HX_STACK_LINE(178)
						if (((e != ::haxe::io::Error_obj::Blocked))){
							HX_STACK_LINE(179)
							doClose = true;
						}
					}
				}
				else {
					HX_STACK_BEGIN_CATCH
					Dynamic e = __e;{
						HX_STACK_LINE(181)
						doClose = true;
					}
				}
			}
		}
		HX_STACK_LINE(185)
		if (((  ((doClose)) ? bool(this->get_connected()) : bool(false) ))){
			HX_STACK_LINE(186)
			this->_connected = false;
			HX_STACK_LINE(187)
			this->cleanSocket();
			HX_STACK_LINE(188)
			::openfl::_v2::events::Event _g3 = ::openfl::_v2::events::Event_obj::__new(::openfl::_v2::events::Event_obj::CLOSE,null(),null());		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(188)
			this->dispatchEvent(_g3);
		}
		else{
			HX_STACK_LINE(189)
			if ((doClose)){
				HX_STACK_LINE(190)
				this->_connected = false;
				HX_STACK_LINE(191)
				this->cleanSocket();
				HX_STACK_LINE(192)
				::openfl::events::IOErrorEvent _g4 = ::openfl::events::IOErrorEvent_obj::__new(::openfl::events::IOErrorEvent_obj::IO_ERROR,true,false,HX_CSTRING("Connection failed"),null());		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(192)
				this->dispatchEvent(_g4);
			}
			else{
				HX_STACK_LINE(193)
				if ((doConnect)){
					HX_STACK_LINE(194)
					this->_connected = true;
					HX_STACK_LINE(195)
					::openfl::_v2::events::Event _g5 = ::openfl::_v2::events::Event_obj::__new(::openfl::_v2::events::Event_obj::CONNECT,null(),null());		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(195)
					this->dispatchEvent(_g5);
				}
			}
		}
		HX_STACK_LINE(198)
		if (((bLength > (int)0))){
			HX_STACK_LINE(199)
			::haxe::io::Bytes newData = b->getBytes();		HX_STACK_VAR(newData,"newData");
			HX_STACK_LINE(200)
			int rl = (this->_input->length - this->_input->position);		HX_STACK_VAR(rl,"rl");
			HX_STACK_LINE(201)
			::openfl::_v2::utils::ByteArray newInput = ::openfl::_v2::utils::ByteArray_obj::__new((rl + newData->length));		HX_STACK_VAR(newInput,"newInput");
			HX_STACK_LINE(202)
			newInput->blit((int)0,this->_input,this->_input->position,rl);
			HX_STACK_LINE(203)
			newInput->blit(rl,newData,(int)0,newData->length);
			HX_STACK_LINE(204)
			this->_input = newInput;
			HX_STACK_LINE(205)
			::openfl::events::ProgressEvent _g6 = ::openfl::events::ProgressEvent_obj::__new(::openfl::events::ProgressEvent_obj::SOCKET_DATA,false,false,newData->length,(int)0);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(205)
			this->dispatchEvent(_g6);
		}
		HX_STACK_LINE(208)
		if (((this->_socket != null()))){
			HX_STACK_LINE(209)
			try
			{
			HX_STACK_CATCHABLE(::openfl::errors::IOError, 0);
			{
				HX_STACK_LINE(210)
				this->flush();
			}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::openfl::errors::IOError >() ){
					HX_STACK_BEGIN_CATCH
					::openfl::errors::IOError e = __e;{
						HX_STACK_LINE(212)
						::openfl::events::IOErrorEvent _g7 = ::openfl::events::IOErrorEvent_obj::__new(::openfl::events::IOErrorEvent_obj::IO_ERROR,true,false,e->message,null());		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(212)
						this->dispatchEvent(_g7);
					}
				}
				else {
				    HX_STACK_DO_THROW(__e);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,onFrame,(void))

Void Socket_obj::cleanSocket( ){
{
		HX_STACK_FRAME("openfl.net.Socket","cleanSocket",0x9ff62390,"openfl.net.Socket.cleanSocket","openfl/net/Socket.hx",218,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(219)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(220)
			this->_socket->close();
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
				}
			}
		}
		HX_STACK_LINE(223)
		this->_socket = null();
		HX_STACK_LINE(224)
		::openfl::_v2::Lib_obj::get_current()->removeEventListener(::openfl::_v2::events::Event_obj::ENTER_FRAME,this->onFrame_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,cleanSocket,(void))

Void Socket_obj::close( ){
{
		HX_STACK_FRAME("openfl.net.Socket","close",0x490d2e2c,"openfl.net.Socket.close","openfl/net/Socket.hx",228,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(228)
		if (((this->_socket != null()))){
			HX_STACK_LINE(229)
			this->cleanSocket();
		}
		else{
			HX_STACK_LINE(231)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,close,(void))

bool Socket_obj::readBoolean( ){
	HX_STACK_FRAME("openfl.net.Socket","readBoolean",0x5d02e366,"openfl.net.Socket.readBoolean","openfl/net/Socket.hx",237,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(238)
	if (((this->_socket == null()))){
		HX_STACK_LINE(239)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(240)
	::openfl::_v2::utils::ByteArray _this = this->_input;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(240)
	if (((_this->position < _this->length))){
		HX_STACK_LINE(240)
		int _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(240)
		{
			HX_STACK_LINE(240)
			int pos = (_this->position)++;		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(240)
			_g = _this->b->__get(pos);
		}
		HX_STACK_LINE(240)
		return (_g != (int)0);
	}
	else{
		HX_STACK_LINE(240)
		int _g1 = _this->__throwEOFi();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(240)
		return (_g1 != (int)0);
	}
	HX_STACK_LINE(240)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readBoolean,return )

int Socket_obj::readByte( ){
	HX_STACK_FRAME("openfl.net.Socket","readByte",0x860f638a,"openfl.net.Socket.readByte","openfl/net/Socket.hx",242,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(243)
	if (((this->_socket == null()))){
		HX_STACK_LINE(244)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(245)
	::openfl::_v2::utils::ByteArray _this = this->_input;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(245)
	int value;		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(245)
	if (((_this->position < _this->length))){
		HX_STACK_LINE(245)
		int pos = (_this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(245)
		value = _this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(245)
		value = _this->__throwEOFi();
	}
	HX_STACK_LINE(245)
	if (((((int(value) & int((int)128))) != (int)0))){
		HX_STACK_LINE(245)
		return (value - (int)256);
	}
	else{
		HX_STACK_LINE(245)
		return value;
	}
	HX_STACK_LINE(245)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readByte,return )

Void Socket_obj::readBytes( ::openfl::_v2::utils::ByteArray bytes,hx::Null< int >  __o_offset,hx::Null< int >  __o_length){
int offset = __o_offset.Default(0);
int length = __o_length.Default(0);
	HX_STACK_FRAME("openfl.net.Socket","readBytes",0xc767b5a9,"openfl.net.Socket.readBytes","openfl/net/Socket.hx",247,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_ARG(offset,"offset")
	HX_STACK_ARG(length,"length")
{
		HX_STACK_LINE(248)
		if (((this->_socket == null()))){
			HX_STACK_LINE(249)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(250)
		this->_input->readBytes(bytes,offset,length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Socket_obj,readBytes,(void))

Float Socket_obj::readDouble( ){
	HX_STACK_FRAME("openfl.net.Socket","readDouble",0xbeb31413,"openfl.net.Socket.readDouble","openfl/net/Socket.hx",252,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(253)
	if (((this->_socket == null()))){
		HX_STACK_LINE(254)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(255)
	return this->_input->readDouble();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readDouble,return )

Float Socket_obj::readFloat( ){
	HX_STACK_FRAME("openfl.net.Socket","readFloat",0x0c6672da,"openfl.net.Socket.readFloat","openfl/net/Socket.hx",257,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(258)
	if (((this->_socket == null()))){
		HX_STACK_LINE(259)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(260)
	return this->_input->readFloat();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readFloat,return )

int Socket_obj::readInt( ){
	HX_STACK_FRAME("openfl.net.Socket","readInt",0x12fd4ead,"openfl.net.Socket.readInt","openfl/net/Socket.hx",262,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(263)
	if (((this->_socket == null()))){
		HX_STACK_LINE(264)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(265)
	return this->_input->readInt();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readInt,return )

::String Socket_obj::readMultiByte( int length,::String charSet){
	HX_STACK_FRAME("openfl.net.Socket","readMultiByte",0x24dd2a5f,"openfl.net.Socket.readMultiByte","openfl/net/Socket.hx",267,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(length,"length")
	HX_STACK_ARG(charSet,"charSet")
	HX_STACK_LINE(268)
	if (((this->_socket == null()))){
		HX_STACK_LINE(269)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(270)
	return this->_input->readUTFBytes(length);
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,readMultiByte,return )

int Socket_obj::readShort( ){
	HX_STACK_FRAME("openfl.net.Socket","readShort",0x85f731ba,"openfl.net.Socket.readShort","openfl/net/Socket.hx",273,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(274)
	if (((this->_socket == null()))){
		HX_STACK_LINE(275)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(276)
	return this->_input->readShort();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readShort,return )

int Socket_obj::readUnsignedByte( ){
	HX_STACK_FRAME("openfl.net.Socket","readUnsignedByte",0xa58d611f,"openfl.net.Socket.readUnsignedByte","openfl/net/Socket.hx",278,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(279)
	if (((this->_socket == null()))){
		HX_STACK_LINE(280)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(281)
	::openfl::_v2::utils::ByteArray _this = this->_input;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(281)
	if (((_this->position < _this->length))){
		HX_STACK_LINE(281)
		int pos = (_this->position)++;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(281)
		return _this->b->__get(pos);
	}
	else{
		HX_STACK_LINE(281)
		return _this->__throwEOFi();
	}
	HX_STACK_LINE(281)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readUnsignedByte,return )

int Socket_obj::readUnsignedInt( ){
	HX_STACK_FRAME("openfl.net.Socket","readUnsignedInt",0xc079dab8,"openfl.net.Socket.readUnsignedInt","openfl/net/Socket.hx",283,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(284)
	if (((this->_socket == null()))){
		HX_STACK_LINE(285)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(286)
	return this->_input->readUnsignedInt();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readUnsignedInt,return )

int Socket_obj::readUnsignedShort( ){
	HX_STACK_FRAME("openfl.net.Socket","readUnsignedShort",0xf4b71685,"openfl.net.Socket.readUnsignedShort","openfl/net/Socket.hx",288,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(289)
	if (((this->_socket == null()))){
		HX_STACK_LINE(290)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(291)
	return this->_input->readUnsignedShort();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readUnsignedShort,return )

::String Socket_obj::readUTF( ){
	HX_STACK_FRAME("openfl.net.Socket","readUTF",0x130652e5,"openfl.net.Socket.readUTF","openfl/net/Socket.hx",293,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(294)
	if (((this->_socket == null()))){
		HX_STACK_LINE(295)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(296)
	return this->_input->readUTF();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,readUTF,return )

::String Socket_obj::readUTFBytes( int length){
	HX_STACK_FRAME("openfl.net.Socket","readUTFBytes",0x5b4f8746,"openfl.net.Socket.readUTFBytes","openfl/net/Socket.hx",298,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(length,"length")
	HX_STACK_LINE(299)
	if (((this->_socket == null()))){
		HX_STACK_LINE(300)
		HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
	}
	HX_STACK_LINE(301)
	return this->_input->readUTFBytes(length);
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,readUTFBytes,return )

Void Socket_obj::writeBoolean( bool value){
{
		HX_STACK_FRAME("openfl.net.Socket","writeBoolean",0x4c6def95,"openfl.net.Socket.writeBoolean","openfl/net/Socket.hx",306,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(307)
		if (((this->_socket == null()))){
			HX_STACK_LINE(308)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(309)
		this->_output->writeBoolean(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,writeBoolean,(void))

Void Socket_obj::writeByte( int value){
{
		HX_STACK_FRAME("openfl.net.Socket","writeByte",0x82bf73fb,"openfl.net.Socket.writeByte","openfl/net/Socket.hx",311,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(312)
		if (((this->_socket == null()))){
			HX_STACK_LINE(313)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(314)
		{
			HX_STACK_LINE(314)
			::openfl::_v2::utils::ByteArray _this = this->_output;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(314)
			_this->ensureElem(_this->position,true);
			HX_STACK_LINE(314)
			int _g = (_this->position)++;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(314)
			_this->b[_g] = value;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,writeByte,(void))

Void Socket_obj::writeBytes( ::openfl::_v2::utils::ByteArray bytes,hx::Null< int >  __o_offset,hx::Null< int >  __o_length){
int offset = __o_offset.Default(0);
int length = __o_length.Default(0);
	HX_STACK_FRAME("openfl.net.Socket","writeBytes",0xe4c60818,"openfl.net.Socket.writeBytes","openfl/net/Socket.hx",316,0x34d23f5a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_ARG(offset,"offset")
	HX_STACK_ARG(length,"length")
{
		HX_STACK_LINE(317)
		if (((this->_socket == null()))){
			HX_STACK_LINE(318)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(319)
		this->_output->writeBytes(bytes,offset,length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Socket_obj,writeBytes,(void))

Void Socket_obj::writeDouble( Float value){
{
		HX_STACK_FRAME("openfl.net.Socket","writeDouble",0x53dce2c4,"openfl.net.Socket.writeDouble","openfl/net/Socket.hx",321,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(322)
		if (((this->_socket == null()))){
			HX_STACK_LINE(323)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(324)
		this->_output->writeDouble(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,writeDouble,(void))

Void Socket_obj::writeFloat( Float value){
{
		HX_STACK_FRAME("openfl.net.Socket","writeFloat",0x29c4c549,"openfl.net.Socket.writeFloat","openfl/net/Socket.hx",326,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(327)
		if (((this->_socket == null()))){
			HX_STACK_LINE(328)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(329)
		this->_output->writeFloat(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,writeFloat,(void))

Void Socket_obj::writeInt( int value){
{
		HX_STACK_FRAME("openfl.net.Socket","writeInt",0x40e4d75c,"openfl.net.Socket.writeInt","openfl/net/Socket.hx",331,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(332)
		if (((this->_socket == null()))){
			HX_STACK_LINE(333)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(334)
		this->_output->writeInt(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,writeInt,(void))

Void Socket_obj::writeMultiByte( ::String value,::String charSet){
{
		HX_STACK_FRAME("openfl.net.Socket","writeMultiByte",0x0e46e04e,"openfl.net.Socket.writeMultiByte","openfl/net/Socket.hx",336,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_ARG(charSet,"charSet")
		HX_STACK_LINE(337)
		if (((this->_socket == null()))){
			HX_STACK_LINE(338)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(339)
		this->_output->writeUTFBytes(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,writeMultiByte,(void))

Void Socket_obj::writeShort( int value){
{
		HX_STACK_FRAME("openfl.net.Socket","writeShort",0xa3558429,"openfl.net.Socket.writeShort","openfl/net/Socket.hx",341,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(342)
		if (((this->_socket == null()))){
			HX_STACK_LINE(343)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(344)
		this->_output->writeShort(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,writeShort,(void))

Void Socket_obj::writeUTF( ::String value){
{
		HX_STACK_FRAME("openfl.net.Socket","writeUTF",0x40eddb94,"openfl.net.Socket.writeUTF","openfl/net/Socket.hx",346,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(347)
		if (((this->_socket == null()))){
			HX_STACK_LINE(348)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(349)
		this->_output->writeUTF(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,writeUTF,(void))

Void Socket_obj::writeUTFBytes( ::String value){
{
		HX_STACK_FRAME("openfl.net.Socket","writeUTFBytes",0xe98f2437,"openfl.net.Socket.writeUTFBytes","openfl/net/Socket.hx",351,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(352)
		if (((this->_socket == null()))){
			HX_STACK_LINE(353)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(354)
		this->_output->writeUTFBytes(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,writeUTFBytes,(void))

Void Socket_obj::writeUnsignedInt( int value){
{
		HX_STACK_FRAME("openfl.net.Socket","writeUnsignedInt",0x20302a67,"openfl.net.Socket.writeUnsignedInt","openfl/net/Socket.hx",356,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(357)
		if (((this->_socket == null()))){
			HX_STACK_LINE(358)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(359)
		this->_output->writeUnsignedInt(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,writeUnsignedInt,(void))

Void Socket_obj::flush( ){
{
		HX_STACK_FRAME("openfl.net.Socket","flush",0x03457938,"openfl.net.Socket.flush","openfl/net/Socket.hx",388,0x34d23f5a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(389)
		if (((this->_socket == null()))){
			HX_STACK_LINE(390)
			HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
		}
		HX_STACK_LINE(391)
		if (((this->_output->length > (int)0))){
			HX_STACK_LINE(392)
			try
			{
			HX_STACK_CATCHABLE(Dynamic, 0);
			{
				HX_STACK_LINE(396)
				this->_socket->output->write(this->_output);
				HX_STACK_LINE(398)
				::openfl::_v2::utils::ByteArray _g = ::openfl::_v2::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(398)
				this->_output = _g;
				HX_STACK_LINE(399)
				::String _g1 = this->get_endian();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(399)
				this->_output->set_endian(_g1);
			}
			}
			catch(Dynamic __e){
				{
					HX_STACK_BEGIN_CATCH
					Dynamic e = __e;{
						HX_STACK_LINE(401)
						HX_STACK_DO_THROW(::openfl::errors::IOError_obj::__new(HX_CSTRING("Operation attempted on invalid socket.")));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,flush,(void))


Socket_obj::Socket_obj()
{
}

void Socket_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Socket);
	HX_MARK_MEMBER_NAME(_stamp,"_stamp");
	HX_MARK_MEMBER_NAME(_buf,"_buf");
	HX_MARK_MEMBER_NAME(_socket,"_socket");
	HX_MARK_MEMBER_NAME(_connected,"_connected");
	HX_MARK_MEMBER_NAME(_host,"_host");
	HX_MARK_MEMBER_NAME(_port,"_port");
	HX_MARK_MEMBER_NAME(_inputBuffer,"_inputBuffer");
	HX_MARK_MEMBER_NAME(_input,"_input");
	HX_MARK_MEMBER_NAME(_output,"_output");
	HX_MARK_MEMBER_NAME(bytesAvailable,"bytesAvailable");
	HX_MARK_MEMBER_NAME(bytesPending,"bytesPending");
	HX_MARK_MEMBER_NAME(timeout,"timeout");
	HX_MARK_MEMBER_NAME(objectEncoding,"objectEncoding");
	HX_MARK_MEMBER_NAME(endian,"endian");
	HX_MARK_MEMBER_NAME(connected,"connected");
	::openfl::_v2::events::EventDispatcher_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Socket_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_stamp,"_stamp");
	HX_VISIT_MEMBER_NAME(_buf,"_buf");
	HX_VISIT_MEMBER_NAME(_socket,"_socket");
	HX_VISIT_MEMBER_NAME(_connected,"_connected");
	HX_VISIT_MEMBER_NAME(_host,"_host");
	HX_VISIT_MEMBER_NAME(_port,"_port");
	HX_VISIT_MEMBER_NAME(_inputBuffer,"_inputBuffer");
	HX_VISIT_MEMBER_NAME(_input,"_input");
	HX_VISIT_MEMBER_NAME(_output,"_output");
	HX_VISIT_MEMBER_NAME(bytesAvailable,"bytesAvailable");
	HX_VISIT_MEMBER_NAME(bytesPending,"bytesPending");
	HX_VISIT_MEMBER_NAME(timeout,"timeout");
	HX_VISIT_MEMBER_NAME(objectEncoding,"objectEncoding");
	HX_VISIT_MEMBER_NAME(endian,"endian");
	HX_VISIT_MEMBER_NAME(connected,"connected");
	::openfl::_v2::events::EventDispatcher_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Socket_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_buf") ) { return _buf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_host") ) { return _host; }
		if (HX_FIELD_EQ(inName,"_port") ) { return _port; }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"flush") ) { return flush_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_stamp") ) { return _stamp; }
		if (HX_FIELD_EQ(inName,"_input") ) { return _input; }
		if (HX_FIELD_EQ(inName,"endian") ) { return inCallProp ? get_endian() : endian; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_socket") ) { return _socket; }
		if (HX_FIELD_EQ(inName,"_output") ) { return _output; }
		if (HX_FIELD_EQ(inName,"timeout") ) { return timeout; }
		if (HX_FIELD_EQ(inName,"connect") ) { return connect_dyn(); }
		if (HX_FIELD_EQ(inName,"onFrame") ) { return onFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt") ) { return readInt_dyn(); }
		if (HX_FIELD_EQ(inName,"readUTF") ) { return readUTF_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt") ) { return writeInt_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUTF") ) { return writeUTF_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"connected") ) { return inCallProp ? get_connected() : connected; }
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"readFloat") ) { return readFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"readShort") ) { return readShort_dyn(); }
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_connected") ) { return _connected; }
		if (HX_FIELD_EQ(inName,"get_endian") ) { return get_endian_dyn(); }
		if (HX_FIELD_EQ(inName,"set_endian") ) { return set_endian_dyn(); }
		if (HX_FIELD_EQ(inName,"readDouble") ) { return readDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"writeFloat") ) { return writeFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"writeShort") ) { return writeShort_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"cleanSocket") ) { return cleanSocket_dyn(); }
		if (HX_FIELD_EQ(inName,"readBoolean") ) { return readBoolean_dyn(); }
		if (HX_FIELD_EQ(inName,"writeDouble") ) { return writeDouble_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_inputBuffer") ) { return _inputBuffer; }
		if (HX_FIELD_EQ(inName,"bytesPending") ) { return inCallProp ? get_bytesPending() : bytesPending; }
		if (HX_FIELD_EQ(inName,"readUTFBytes") ) { return readUTFBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"writeBoolean") ) { return writeBoolean_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_connected") ) { return get_connected_dyn(); }
		if (HX_FIELD_EQ(inName,"readMultiByte") ) { return readMultiByte_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUTFBytes") ) { return writeUTFBytes_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bytesAvailable") ) { return inCallProp ? get_bytesAvailable() : bytesAvailable; }
		if (HX_FIELD_EQ(inName,"objectEncoding") ) { return objectEncoding; }
		if (HX_FIELD_EQ(inName,"writeMultiByte") ) { return writeMultiByte_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"readUnsignedInt") ) { return readUnsignedInt_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_bytesPending") ) { return get_bytesPending_dyn(); }
		if (HX_FIELD_EQ(inName,"readUnsignedByte") ) { return readUnsignedByte_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUnsignedInt") ) { return writeUnsignedInt_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"readUnsignedShort") ) { return readUnsignedShort_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_bytesAvailable") ) { return get_bytesAvailable_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Socket_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_buf") ) { _buf=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_host") ) { _host=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_port") ) { _port=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_stamp") ) { _stamp=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_input") ) { _input=inValue.Cast< ::openfl::_v2::utils::ByteArray >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endian") ) { if (inCallProp) return set_endian(inValue);endian=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_socket") ) { _socket=inValue.Cast< ::sys::net::Socket >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_output") ) { _output=inValue.Cast< ::openfl::_v2::utils::ByteArray >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timeout") ) { timeout=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"connected") ) { connected=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_connected") ) { _connected=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_inputBuffer") ) { _inputBuffer=inValue.Cast< ::openfl::_v2::utils::ByteArray >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bytesPending") ) { bytesPending=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bytesAvailable") ) { bytesAvailable=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"objectEncoding") ) { objectEncoding=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Socket_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_stamp"));
	outFields->push(HX_CSTRING("_buf"));
	outFields->push(HX_CSTRING("_socket"));
	outFields->push(HX_CSTRING("_connected"));
	outFields->push(HX_CSTRING("_host"));
	outFields->push(HX_CSTRING("_port"));
	outFields->push(HX_CSTRING("_inputBuffer"));
	outFields->push(HX_CSTRING("_input"));
	outFields->push(HX_CSTRING("_output"));
	outFields->push(HX_CSTRING("bytesAvailable"));
	outFields->push(HX_CSTRING("bytesPending"));
	outFields->push(HX_CSTRING("timeout"));
	outFields->push(HX_CSTRING("objectEncoding"));
	outFields->push(HX_CSTRING("endian"));
	outFields->push(HX_CSTRING("connected"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Socket_obj,_stamp),HX_CSTRING("_stamp")},
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(Socket_obj,_buf),HX_CSTRING("_buf")},
	{hx::fsObject /*::sys::net::Socket*/ ,(int)offsetof(Socket_obj,_socket),HX_CSTRING("_socket")},
	{hx::fsBool,(int)offsetof(Socket_obj,_connected),HX_CSTRING("_connected")},
	{hx::fsString,(int)offsetof(Socket_obj,_host),HX_CSTRING("_host")},
	{hx::fsInt,(int)offsetof(Socket_obj,_port),HX_CSTRING("_port")},
	{hx::fsObject /*::openfl::_v2::utils::ByteArray*/ ,(int)offsetof(Socket_obj,_inputBuffer),HX_CSTRING("_inputBuffer")},
	{hx::fsObject /*::openfl::_v2::utils::ByteArray*/ ,(int)offsetof(Socket_obj,_input),HX_CSTRING("_input")},
	{hx::fsObject /*::openfl::_v2::utils::ByteArray*/ ,(int)offsetof(Socket_obj,_output),HX_CSTRING("_output")},
	{hx::fsInt,(int)offsetof(Socket_obj,bytesAvailable),HX_CSTRING("bytesAvailable")},
	{hx::fsInt,(int)offsetof(Socket_obj,bytesPending),HX_CSTRING("bytesPending")},
	{hx::fsInt,(int)offsetof(Socket_obj,timeout),HX_CSTRING("timeout")},
	{hx::fsInt,(int)offsetof(Socket_obj,objectEncoding),HX_CSTRING("objectEncoding")},
	{hx::fsString,(int)offsetof(Socket_obj,endian),HX_CSTRING("endian")},
	{hx::fsBool,(int)offsetof(Socket_obj,connected),HX_CSTRING("connected")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_stamp"),
	HX_CSTRING("_buf"),
	HX_CSTRING("_socket"),
	HX_CSTRING("_connected"),
	HX_CSTRING("_host"),
	HX_CSTRING("_port"),
	HX_CSTRING("_inputBuffer"),
	HX_CSTRING("_input"),
	HX_CSTRING("_output"),
	HX_CSTRING("bytesAvailable"),
	HX_CSTRING("bytesPending"),
	HX_CSTRING("timeout"),
	HX_CSTRING("objectEncoding"),
	HX_CSTRING("endian"),
	HX_CSTRING("connected"),
	HX_CSTRING("get_connected"),
	HX_CSTRING("get_endian"),
	HX_CSTRING("set_endian"),
	HX_CSTRING("get_bytesAvailable"),
	HX_CSTRING("get_bytesPending"),
	HX_CSTRING("connect"),
	HX_CSTRING("onFrame"),
	HX_CSTRING("cleanSocket"),
	HX_CSTRING("close"),
	HX_CSTRING("readBoolean"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("readDouble"),
	HX_CSTRING("readFloat"),
	HX_CSTRING("readInt"),
	HX_CSTRING("readMultiByte"),
	HX_CSTRING("readShort"),
	HX_CSTRING("readUnsignedByte"),
	HX_CSTRING("readUnsignedInt"),
	HX_CSTRING("readUnsignedShort"),
	HX_CSTRING("readUTF"),
	HX_CSTRING("readUTFBytes"),
	HX_CSTRING("writeBoolean"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeDouble"),
	HX_CSTRING("writeFloat"),
	HX_CSTRING("writeInt"),
	HX_CSTRING("writeMultiByte"),
	HX_CSTRING("writeShort"),
	HX_CSTRING("writeUTF"),
	HX_CSTRING("writeUTFBytes"),
	HX_CSTRING("writeUnsignedInt"),
	HX_CSTRING("flush"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Socket_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Socket_obj::__mClass,"__mClass");
};

#endif

Class Socket_obj::__mClass;

void Socket_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.net.Socket"), hx::TCanCast< Socket_obj> ,sStaticFields,sMemberFields,
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

void Socket_obj::__boot()
{
}

} // end namespace openfl
} // end namespace net
