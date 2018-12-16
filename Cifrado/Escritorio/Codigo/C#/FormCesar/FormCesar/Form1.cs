using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FormCesar
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e) {
            char[] alfabeto = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
            int desplazamiento = 0;
            string salida = "";
            string outTransposicion = "";
            string outTransposicionAgrupada = "";
            string auxi = txtGrupos.Text;
            desplazamiento = int.Parse(inputDesplazamiento.Text);
	        for(int i = 0; i < txtTextoPlano.Text.Length; i++){
                if (txtTextoPlano.Text[i] != 32) {
			        for(int j = 0; j < 26; j++){
                        if (txtTextoPlano.Text[i] == alfabeto[j]) {
					        int aux = (j + desplazamiento) % 26;
                            salida += alfabeto[aux].ToString();
					        break;
				        }
			        }	
		        }
	        }
            txtTextoAnalizado.Text = salida;

            for(int i = 0; i < txtTextoAnalizado.Text.Length; i++){
		        if(txtTextoAnalizado.Text[i] != 32){
			       for(int j = 0; j < 26; j++){
				       if(txtTextoAnalizado.Text[i] == alfabeto[j]){
				            Int32 aux;
				            if((j-desplazamiento) < 0){
					            aux = 26 + (j-desplazamiento);
					         }
					         else{
					            aux = (j-desplazamiento) % 26;
					         }
					         outTransposicion += alfabeto[aux].ToString();
					         break;
				       }
			       }
		        }		
	        }
            txtTransposicion.Text = outTransposicion;

            
            /*if (desplazamiento <= txtTextoPlano.Text.Length) {
                for (int j = 0; j < txtTextoPlano.Text.Length; j += desplazamiento) {
                     int k = j;
                     for (k = k + j; k > 0; k--) {
                          outTransposicionAgrupada += auxi[k];
                     }
                 }
             }
           txtGrupos.Text = outTransposicionAgrupada;*/
        }

        private void inputDesplazamiento_ValueChanged(object sender, EventArgs e) {
            char[] alfabeto = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
            int desplazamiento = 0;
            string salida = "";
            string outTransposicion = "";
            desplazamiento = int.Parse(inputDesplazamiento.Text);
            for (int i = 0; i < txtTextoPlano.Text.Length; i++) {
                if (txtTextoPlano.Text[i] != 32) {
                    for (int j = 0; j < 26; j++) {
                        if (txtTextoPlano.Text[i] == alfabeto[j]) {
                            int aux = (j + desplazamiento) % 26;
                            salida += alfabeto[aux].ToString();
                            break;
                        }
                    }
                }
            }
            txtTextoAnalizado.Text = salida;

            for (int i = 0; i < txtTextoAnalizado.Text.Length; i++) {
                if (txtTextoAnalizado.Text[i] != 32) {
                    for (int j = 0; j < 26; j++) {
                        if (txtTextoAnalizado.Text[i] == alfabeto[j]) {
                            Int32 aux;
                            if ((j - desplazamiento) < 0) {
                                aux = 26 + (j - desplazamiento);
                            } else {
                                aux = (j - desplazamiento) % 26;
                            }
                            outTransposicion += alfabeto[aux].ToString();
                            break;
                        }
                    }
                }
            }
            txtTransposicion.Text = outTransposicion;
        }
    }
}
