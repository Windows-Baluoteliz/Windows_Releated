#pragma once

namespace CPlus_Baluoteliz{

	namespace Windows_Mianshi{

		
		/*whether in chinese or english,one work character take up 2 bytes.
		* the byte terminate is '\0' or 'cc'
		*/
		struct CCommonFun{

			static int getSystemDefCharcterSize(){

				TCHAR sz = L'\0';
				return sizeof(sz);
			}


		};
	}
}