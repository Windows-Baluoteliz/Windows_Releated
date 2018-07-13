#pragma once

namespace CPlus_Baluoteliz{

	namespace Windows_Mianshi{

		
		/*whether in chinese or english,one work character take up 2 bytes.
		* the byte terminate is '\0' or 'cc'
		*/
		struct CCommonFun{

			static int getSystemDefCharcterSize(){

				return sizeof(TCHAR);
			}
			
			/*
			* NewworkEndian test 
			* default x0x86 architecture is big endian
			* NetTransfer need use big endian
			* transfer api is htonl;
			*/
			static void NetWorkEndian() {
				
				int nNum = 0x12345678;

				TRACE("[0]:0x%x\n", *((char*)&nNum + 0));
				TRACE("[1]:0x%x\n", *((char*)&nNum + 1));
				TRACE("[2]:0x%x\n", *((char*)&nNum + 2));
				TRACE("[3]:0x%x\n", *((char*)&nNum + 3));

				int nNum1 = htonl(nNum);
				TRACE("[0]:0x%x\n", *((char*)&nNum1 + 0));
				TRACE("[1]:0x%x\n", *((char*)&nNum1 + 1));
				TRACE("[2]:0x%x\n", *((char*)&nNum1 + 2));
				TRACE("[3]:0x%x\n", *((char*)&nNum1 + 3));
			}

			static void FileOperatorStdcall() {
				
				
			}

			static void FileOperatorCdecl() {

				FILE* pFile = fopen("..\\test.dat", "w");
				if (pFile) {

					int nNum = 0;
					for (int nRow = 0; 10 > nRow; nRow++) {
						scanf("%d", nNum);
						fprintf(pFile, "[%d]: %d\n", nRow, nNum);
					}

					fclose(pFile);
					pFile = NULL;
				}

				pFile = fopen("..\\test.dat", "r");
				if (pFile) {

					while (!feof(pFile)) {
						int nNum = 0;
						static int nRow = 0;
						fscanf(pFile, "%d", &nNum);
						printf("[%d]:%d\n",nRow,nNum);
						nRow++;
					}
				}
			}
		};

		typedef struct eTagMemoryAlignment{

			eTagMemoryAlignment(){
				nNum = 1;
				chTemp = 'a';
				memset(chArray,1,10);
			}

			~eTagMemoryAlignment(){ ; }

			bool operator < (const eTagMemoryAlignment &ma){
				if (this != &ma) {
					return nNum < ma.nNum;
				}
			}

			int nNum;
			char chTemp;
			char chArray[10];
		}MEMROYALIGNMENT,*PMEMORYALIGNMENT,*LPMEMORYALIGNMENT;

	}
}