#include "FormCesar.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CifradoCesarMejorado::FormCesar form;
	Application::Run(%form);
}

System::Void CifradoCesarMejorado::FormCesar::txtTexto_TextChanged(System::Object^  sender, System::EventArgs^  e){
	char alfabeto[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    String ^ in;
	String ^ out;
	String ^ outGrupos;
	Decimal desplaza = inputDesplazamiento -> Value;	
	Decimal num_grupos = numeroGrupos -> Value;
	Int32 input_grupos = System::Convert::ToInt32(num_grupos);
	Int32 desplazamiento = System::Convert::ToInt32(desplaza);
			
	for(int i = 0; i < txtTexto -> Text -> Length; i++){
        if (txtTexto -> Text[i] != 32) {
	        for(int j = 0; j < 26; j++){
                if (txtTexto -> Text[i] == alfabeto[j]) {
			        Int32 aux = (j + desplazamiento) % 26;
					in += System::Convert::ToChar(alfabeto[aux]);
					txtTextoAnalizado -> Text = in;
			        break;
		        }
	        }	
	    }
	}

	for(int i = 0; i < txtTextoAnalizado -> Text -> Length; i++){
		if(txtTextoAnalizado -> Text[i] != 32){
			for(int j = 0; j < 26; j++){
				if(txtTextoAnalizado -> Text[i] == alfabeto[j]){
					Int32 aux;
					if((j-desplazamiento) < 0){
						aux = 26 + (j-desplazamiento);
					}
					else{
						aux = (j-desplazamiento) % 26;
					}
					out += System::Convert::ToChar(alfabeto[aux]);
					txtTrasposicion -> Text = out;
					break;
				}
			}	
		}		
	}

	/*for (int i = 0; i < txtTexto -> Text -> Length; i++) {
		outGrupos += txtTexto -> Text[i];
	}*/
}

System::Void CifradoCesarMejorado::FormCesar::inputDesplazamiento_ValueChanged(System::Object^  sender, System::EventArgs^  e){
	char alfabeto[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    String ^ in;
	Decimal desplaza = inputDesplazamiento -> Value;			
	Int32 desplazamiento = System::Convert::ToInt32(desplaza);
			
	for(int i = 0; i < txtTexto -> Text -> Length; i++){
        if (txtTexto -> Text[i] != 32) {
	        for(int j = 0; j < 26; j++){
                if (txtTexto -> Text[i] == alfabeto[j]) {
			        Int32 aux = (j + desplazamiento) % 26;
					in += System::Convert::ToChar(alfabeto[aux]);
					txtTextoAnalizado -> Text = in;
			        break;
		        }
	        }	
	    }
	}
}