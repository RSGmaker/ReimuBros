/*
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.
 
   Before using, initialize the state by using init_genrand(seed)
   or init_by_array(init_key, key_length).
 
   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.
 
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
 
     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
 
     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
 
     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.
 
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 
   Any feedback is very welcome.
   http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
   email: m-mat @ math.sci.hiroshima-u.ac.jp (remove space)
 
     -------------------
 
     Converted to Actionscript 2005 by John Winkelman
     Feedback welcome at john.winkelman@gmail.com
*/
 
 
/* Period parameters */
//package org.eccesignum.utilities {
package; 
    class MersenneTwister {
        private var N:Int = 624;
        private var M:Int = 397;
        private var MATRIX_A:UInt = 0x9908b0df;   /* constant vector a */
        private var UPPER_MASK:UInt = 0x80000000; /* most significant w-r bits */
        private var LOWER_MASK:UInt = 0x7fffffff; /* least significant r bits */
 
        private var mt:Array<UInt>; /* the array for the state vector  */
        private var mti:Int;
 
        public var seed:UInt;
        private var returnLength:Int;
        private var maxSize:Int;
 
        private var returnArray:Array<Int>;
		public function new() 
		{
			seed = 0;
		}
 
 
        /*public function MersenneTwister():void {
 
        }*/
		public function random():Float
		{
			return quick(100000) * 0.00001;
		}
		public function quick(TTmaxSize:Int):Int
		{
			return twist(seed, 1, TTmaxSize)[0];
		}
		public function bool():Bool
		{
			return (quick(100) < 50);
		}
        public function twist(TTseed:UInt=0,TTreturnLength:Int,TTmaxSize:Int):Array<Int> {    //    seed number, number of values to return ,max size of returned number
            if (TTseed != 0)
			{
				seed = TTseed;
			}
            returnLength = TTreturnLength;
            maxSize = TTmaxSize;
            mt = [];
 
            returnArray = [];
 
            mti = N+1; /* mti==N+1 means mt[N] is not initialized */
            var i:Int;
            //var initArray=(0x123, 0x234, 0x345, 0x456);    //2010.04.20    modiied to the below
            var initArray:Array<UInt> = [0x123, 0x234, 0x345, 0x456];
            init_by_array(initArray, initArray.length);
			i = 0;
            /*for (i=0; i<returnLength; i++) {
                returnArray[i] = genrand_int32()%maxSize;
            }*/
			while (i < returnLength)
			{
				returnArray[i] = genrand_int32()%maxSize;
				i++;
			}
			seed = genrand_int32();
            //returnArray.sort(16);
            //trace(returnArray);
            /*
            trace("\n1000 outputs of genrand_real2()\n");
            for (i=0; i<returnLength; i++) {
              trace(" " + genrand_real2());
              if (i%5==4) trace("\n");
            }
            */
            return returnArray;
 
        }
 
 
        /* initializes mt[N] with a seed */
        private function init_genrand(TTseed:UInt):Void {
            mt[0] = TTseed & 0xffffffff;
			mti = 1;
			while (mti < N)
			{
				mt[mti] = (1812433253 * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti);
                mt[mti] &= 0xffffffff;
				mti++;
			}
			/*
            for (mti=1; mti<N; mti++) {
                mt[mti] = (1812433253 * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti);
                mt[mti] &= 0xffffffff;
                // for >32 bit machines
            }*/
        }
 
        /* initialize by an array with array-length */
        /* init_key is the array for initializing keys */
        /* key_length is its length */
        /* slight change for C++, 2004/2/26 */
        //    void init_by_array(unsigned long init_key[], int key_length)
 
        private function init_by_array(TTseedArray:Array<UInt>,TTseedArrayLength:Int):Void {
            var i:Int = 1;
            var j:Int = 0;
            init_genrand(seed);
            //init_genrand(19650218);
            var k:Int = (N > TTseedArrayLength) ? N : TTseedArrayLength;
			while (k > 0)
			{
				mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525)) + TTseedArray[j] + j; // non linear
                mt[i] &= 0xffffffff; // for WORDSIZE > 32 machines
                i++;
                j++;
                if (i >= N) {
                    mt[0] = mt[N-1];
                    i=1;
                }
                if (j >= TTseedArrayLength) j = 0;
				k--;
			}
			k = N - 1;
			while (k > 0)
			{
				mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941)) - i; // non linear
                mt[i] &= 0xffffffff; // for WORDSIZE > 32 machines
                i++;
                if (i>=N) {
                    mt[0] = mt[N-1];
                    i=1;
                }
				k--;
			}
			/*
            for (k; k>0; k--) {
                mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525)) + TTseedArray[j] + j; // non linear
                mt[i] &= 0xffffffff; // for WORDSIZE > 32 machines
                i++;
                j++;
                if (i >= N) {
                    mt[0] = mt[N-1];
                    i=1;
                }
                if (j >= TTseedArrayLength) j=0;
            }
            for (k = N-1; k; k--) {
                mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941)) - i; // non linear
                mt[i] &= 0xffffffff; // for WORDSIZE > 32 machines
                i++;
                if (i>=N) {
                    mt[0] = mt[N-1];
                    i=1;
                }
            }*/
 
            mt[0] = 0x80000000; // MSB is 1; assuring non-zero initial array
        }
 
        /* generates a random number on [0,0xffffffff]-interval */
        private function genrand_int32():UInt    {
            var y:UInt;
            var mag01:Array<UInt>=[0x0, MATRIX_A];
            /* mag01[x] = x * MATRIX_A  for x=0,1 */
 
            if (mti >= N) { /* generate N words at one time */
                var kk:Int;
 
                if (mti == N+1)   /* if init_genrand() has not been called, */
                    init_genrand(5489); /* a default initial seed is used */
				kk = 0;
				while (kk < N - M)
				{
					y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
                    mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1];
					kk++;
				}
				while (kk < N - 1)
				{
					y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
                    mt[kk] = mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1];
					kk++;
				}
 
                /*for (kk=0;kk<N-M;kk++) {
                    y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
                    mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1];
                }
                for (;kk<N-1;kk++) {
                    y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
                    mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1];
                }*/
                y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
                mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1];
 
                mti = 0;
            }
 
            y = mt[mti++];
 
            /* Tempering */
            y ^= (y >> 11);
            y ^= (y << 7) & 0x9d2c5680;
            y ^= (y << 15) & 0xefc60000;
            y ^= (y >> 18);
 
            return y;
        }
 
        // generates a random number on [0,0x7fffffff]-interval
        private function genrand_int31():UInt    {
            return (genrand_int32()>>1);
        }
 
        // generates a random number on [0,1]-real-interval
        /*private function genrand_real1():Number    {
            return genrand_int32()*(1.0/4294967295.0);
            // divided by 2^32-1
        }
 
        // generates a random number on [0,1)-real-interval
        private function genrand_real2():Number {
            return genrand_int32()*(1.0/4294967296.0);
            // divided by 2^32
        }
 
        // generates a random number on (0,1)-real-interval
        private function genrand_real3():Number    {
            return ((genrand_int32()) + 0.5)*(1.0/4294967296.0);
            // divided by 2^32
        }
 
        // generates a random number on [0,1) with 53-bit resolution
        private function genrand_res53():Number    {
            var a:Number = genrand_int32()>>5;
            var b:Number = genrand_int32()>>6;
            return(a*67108864.0+b)*(1.0/9007199254740992.0);
        }*/
        // These real versions are due to Isaku Wada, 2002/01/09 added
    }
