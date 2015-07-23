/*
  Copyright (c) 2008, Adobe Systems Incorporated
  All rights reserved.

  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions are
  met:

  * Redistributions of source code must retain the above copyright notice, 
    this list of conditions and the following disclaimer.
  
  * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the 
    documentation and/or other materials provided with the distribution.
  
  * Neither the name of Adobe Systems Incorporated nor the names of its 
    contributors may be used to endorse or promote products derived from 
    this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
//package com.adobe.utils {
package; 
	
	//import flash.utils.Endian;
	import openfl.utils.Endian;
	/**
	 * Contains reusable methods for operations pertaining 
	 * to int values.
	 */
	class IntUtil {
		
		/**
		 * Rotates x left n bits
		 *
		 * @langversion ActionScript 3.0
		 * @playerversion Flash 9.0
		 * @tiptext
		 */
		public static function rol ( x:Int, n:Int ):Int {
			return ( x << n ) | ( x >>> ( 32 - n ) );
		}
		
		/**
		 * Rotates x right n bits
		 *
		 * @langversion ActionScript 3.0
		 * @playerversion Flash 9.0
		 * @tiptext
		 */
		public static function ror ( x:Int, n:Int ):UInt {
			var nn:Int = 32 - n;
			return ( x << nn ) | ( x >>> ( 32 - nn ) );
		}
		
		/** String for quick lookup of a hex character based on index */
		private static var hexChars:String = "0123456789abcdef";
		
		/**
		 * Outputs the hex value of a int, allowing the developer to specify
		 * the endinaness in the process.  Hex output is lowercase.
		 *
		 * @param n The int value to output as hex
		 * @param bigEndian Flag to output the int as big or little endian
		 * @return A string of length 8 corresponding to the 
		 *		hex representation of n ( minus the leading "0x" )
		 * @langversion ActionScript 3.0
		 * @playerversion Flash 9.0
		 * @tiptext
		 */
		public static function toHex( n:Int, bigEndian:Bool = false ):String {
			var s:String = "";
			
			if ( bigEndian ) {
				//for ( var i:Int = 0; i < 4; i++ ) {
				var i = 0;
				while (i<4){
					s += hexChars.charAt( ( n >> ( ( 3 - i ) * 8 + 4 ) ) & 0xF ) 
						+ hexChars.charAt( ( n >> ( ( 3 - i ) * 8 ) ) & 0xF );
						i++;
				}
			} else {
				//for ( var x:Int = 0; x < 4; x++ ) {
				var x = 0;
				while (x<4){
					s += hexChars.charAt( ( n >> ( x * 8 + 4 ) ) & 0xF )
						+ hexChars.charAt( ( n >> ( x * 8 ) ) & 0xF );
						x++;
				}
			}
			
			return s;
		}
	}
		
