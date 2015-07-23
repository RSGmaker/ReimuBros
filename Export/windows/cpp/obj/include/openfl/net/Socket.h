#ifndef INCLUDED_openfl_net_Socket
#define INCLUDED_openfl_net_Socket

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/events/EventDispatcher.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,utils,ByteArray)
HX_DECLARE_CLASS3(openfl,_v2,utils,IDataInput)
HX_DECLARE_CLASS3(openfl,_v2,utils,IDataOutput)
HX_DECLARE_CLASS3(openfl,_v2,utils,IMemoryRange)
HX_DECLARE_CLASS2(openfl,net,Socket)
HX_DECLARE_CLASS2(sys,net,Socket)
namespace openfl{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  Socket_obj : public ::openfl::_v2::events::EventDispatcher_obj{
	public:
		typedef ::openfl::_v2::events::EventDispatcher_obj super;
		typedef Socket_obj OBJ_;
		Socket_obj();
		Void __construct(::String host,hx::Null< int >  __o_port);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Socket_obj > __new(::String host,hx::Null< int >  __o_port);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Socket_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Socket"); }

		Float _stamp;
		::haxe::io::Bytes _buf;
		::sys::net::Socket _socket;
		bool _connected;
		::String _host;
		int _port;
		::openfl::_v2::utils::ByteArray _inputBuffer;
		::openfl::_v2::utils::ByteArray _input;
		::openfl::_v2::utils::ByteArray _output;
		int bytesAvailable;
		int bytesPending;
		int timeout;
		int objectEncoding;
		::String endian;
		bool connected;
		virtual bool get_connected( );
		Dynamic get_connected_dyn();

		virtual ::String get_endian( );
		Dynamic get_endian_dyn();

		virtual ::String set_endian( ::String value);
		Dynamic set_endian_dyn();

		virtual int get_bytesAvailable( );
		Dynamic get_bytesAvailable_dyn();

		virtual int get_bytesPending( );
		Dynamic get_bytesPending_dyn();

		virtual Void connect( ::String host,Dynamic port);
		Dynamic connect_dyn();

		virtual Void onFrame( Dynamic _);
		Dynamic onFrame_dyn();

		virtual Void cleanSocket( );
		Dynamic cleanSocket_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual bool readBoolean( );
		Dynamic readBoolean_dyn();

		virtual int readByte( );
		Dynamic readByte_dyn();

		virtual Void readBytes( ::openfl::_v2::utils::ByteArray bytes,hx::Null< int >  offset,hx::Null< int >  length);
		Dynamic readBytes_dyn();

		virtual Float readDouble( );
		Dynamic readDouble_dyn();

		virtual Float readFloat( );
		Dynamic readFloat_dyn();

		virtual int readInt( );
		Dynamic readInt_dyn();

		virtual ::String readMultiByte( int length,::String charSet);
		Dynamic readMultiByte_dyn();

		virtual int readShort( );
		Dynamic readShort_dyn();

		virtual int readUnsignedByte( );
		Dynamic readUnsignedByte_dyn();

		virtual int readUnsignedInt( );
		Dynamic readUnsignedInt_dyn();

		virtual int readUnsignedShort( );
		Dynamic readUnsignedShort_dyn();

		virtual ::String readUTF( );
		Dynamic readUTF_dyn();

		virtual ::String readUTFBytes( int length);
		Dynamic readUTFBytes_dyn();

		virtual Void writeBoolean( bool value);
		Dynamic writeBoolean_dyn();

		virtual Void writeByte( int value);
		Dynamic writeByte_dyn();

		virtual Void writeBytes( ::openfl::_v2::utils::ByteArray bytes,hx::Null< int >  offset,hx::Null< int >  length);
		Dynamic writeBytes_dyn();

		virtual Void writeDouble( Float value);
		Dynamic writeDouble_dyn();

		virtual Void writeFloat( Float value);
		Dynamic writeFloat_dyn();

		virtual Void writeInt( int value);
		Dynamic writeInt_dyn();

		virtual Void writeMultiByte( ::String value,::String charSet);
		Dynamic writeMultiByte_dyn();

		virtual Void writeShort( int value);
		Dynamic writeShort_dyn();

		virtual Void writeUTF( ::String value);
		Dynamic writeUTF_dyn();

		virtual Void writeUTFBytes( ::String value);
		Dynamic writeUTFBytes_dyn();

		virtual Void writeUnsignedInt( int value);
		Dynamic writeUnsignedInt_dyn();

		virtual Void flush( );
		Dynamic flush_dyn();

};

} // end namespace openfl
} // end namespace net

#endif /* INCLUDED_openfl_net_Socket */ 
