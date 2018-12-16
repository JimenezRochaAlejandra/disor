#pragma once

namespace CifradoCesarMejorado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormCesar
	/// </summary>
	public ref class FormCesar : public System::Windows::Forms::Form
	{
	public:
		FormCesar(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~FormCesar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  inputDesplazamiento;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtTextoAnalizado;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtTexto;
	private: System::Windows::Forms::TextBox^  txtTrasposicion;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::NumericUpDown^  numeroGrupos;

	private: System::Windows::Forms::Label^  label4;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->inputDesplazamiento = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtTextoAnalizado = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtTrasposicion = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtTexto = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->numeroGrupos = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputDesplazamiento))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numeroGrupos))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->inputDesplazamiento);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->txtTextoAnalizado);
			this->groupBox1->Location = System::Drawing::Point(15, 114);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 205);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"César";
			// 
			// inputDesplazamiento
			// 
			this->inputDesplazamiento->Location = System::Drawing::Point(123, 20);
			this->inputDesplazamiento->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->inputDesplazamiento->Name = L"inputDesplazamiento";
			this->inputDesplazamiento->Size = System::Drawing::Size(71, 20);
			this->inputDesplazamiento->TabIndex = 2;
			this->inputDesplazamiento->ValueChanged += gcnew System::EventHandler(this, &FormCesar::inputDesplazamiento_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(7, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Desplazamiento:";
			// 
			// txtTextoAnalizado
			// 
			this->txtTextoAnalizado->Location = System::Drawing::Point(6, 46);
			this->txtTextoAnalizado->Multiline = true;
			this->txtTextoAnalizado->Name = L"txtTextoAnalizado";
			this->txtTextoAnalizado->Size = System::Drawing::Size(188, 153);
			this->txtTextoAnalizado->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txtTrasposicion);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Location = System::Drawing::Point(221, 114);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 205);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			// 
			// txtTrasposicion
			// 
			this->txtTrasposicion->Location = System::Drawing::Point(7, 46);
			this->txtTrasposicion->Multiline = true;
			this->txtTrasposicion->Name = L"txtTrasposicion";
			this->txtTrasposicion->Size = System::Drawing::Size(187, 153);
			this->txtTrasposicion->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 16);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Trasposición inversa:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Texto:";
			// 
			// txtTexto
			// 
			this->txtTexto->Location = System::Drawing::Point(68, 13);
			this->txtTexto->Multiline = true;
			this->txtTexto->Name = L"txtTexto";
			this->txtTexto->Size = System::Drawing::Size(571, 95);
			this->txtTexto->TabIndex = 3;
			this->txtTexto->TextChanged += gcnew System::EventHandler(this, &FormCesar::txtTexto_TextChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Controls->Add(this->numeroGrupos);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Location = System::Drawing::Point(428, 114);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(211, 205);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Trasposición inversa agrupada";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(10, 46);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(195, 153);
			this->textBox1->TabIndex = 2;
			// 
			// numeroGrupos
			// 
			this->numeroGrupos->Location = System::Drawing::Point(68, 19);
			this->numeroGrupos->Name = L"numeroGrupos";
			this->numeroGrupos->Size = System::Drawing::Size(137, 20);
			this->numeroGrupos->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(7, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 16);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Grupos:";
			// 
			// FormCesar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(657, 329);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->txtTexto);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"FormCesar";
			this->Text = L"FormCesar";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputDesplazamiento))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numeroGrupos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	private: System::Void txtTexto_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void inputDesplazamiento_ValueChanged(System::Object^  sender, System::EventArgs^  e);
};
}
