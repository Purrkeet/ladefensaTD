#pragma once
#include "Enemigo.h"
#include "Mapa.h"
#include "Juego.h"
#include <vector>
namespace LaDefensa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			panel2->Visible=false;
			ParaPausa = false;
			TorreSeleccionada = nullptr;
			oOleada=nullptr;
//			enemigos  = new ArrEnemigos(10);
			oNivel = new CNivel(3);//digamos que tiene 3 oleadas X_X
			pausaLocal = false;
			contadorTiempo=0;
			contDtorre = 0;
			oJuego = new CJuego("Luis Canaval");
			lbl_Dinero->Text = gcnew String(""+oJuego->TotalDinero);
			lbl_puntaje->Text = gcnew String("" + oJuego->Puntaje);
			lbl_vidas->Text = gcnew String("" + oJuego->TotalVidas);
			imgTorre = gcnew Bitmap("pokemonTDSP.png");
			imgTorre->MakeTransparent(imgTorre->GetPixel(0, 0));
			hora_inicial=time(NULL);
			TorreClick = nullptr;
			//cargar imagenes solo 1 vez mucho esfuerzo de CPU
			int cantImgTorres = 8;
			int cantImgEnemigos = 12;
			int cantImgTexturas = 9;
			imgsTorres = gcnew array<Bitmap^>(cantImgTorres);
			imgsTorres[0] = gcnew Bitmap("torre1.png");
			imgsTorres[1] = gcnew Bitmap("torre1sprite.png");
			imgsTorres[2] = gcnew Bitmap("torre2.png");
			imgsTorres[3] = gcnew Bitmap("torre2sprite.png");
			imgsTorres[4] = gcnew Bitmap("torre3.png");
			imgsTorres[5] = gcnew Bitmap("torre3sprite.png");
			imgsTorres[6] = gcnew Bitmap("torre4.png");
			imgsTorres[7] = gcnew Bitmap("torre4sprite.png");
			imgsEnemigos = gcnew array<Bitmap^>(cantImgEnemigos);
			imgsEnemigos[0] = gcnew Bitmap("1nv1d.png");
			imgsEnemigos[1] = gcnew Bitmap("2nv1d.png");
			imgsEnemigos[2] = gcnew Bitmap("3nv1d.png");
			imgsEnemigos[3] = gcnew Bitmap("1nv2d.png");
			imgsEnemigos[4] = gcnew Bitmap("2nv2d.png");
			imgsEnemigos[5] = gcnew Bitmap("3nv2d.png");
			imgsEnemigos[6] = gcnew Bitmap("1nv3d.png");
			imgsEnemigos[7] = gcnew Bitmap("2nv3d.png");
			imgsEnemigos[8] = gcnew Bitmap("3nv3d.png");
			imgsEnemigos[9] = gcnew Bitmap("1nv4d.png");
			imgsEnemigos[10] = gcnew Bitmap("2nv4d.png");
			imgsEnemigos[11] = gcnew Bitmap("3nv4d.png");

			imgsTexturas = gcnew array<Bitmap^>(cantImgTexturas);
			imgsTexturas[0] = gcnew Bitmap("fondo1.png");
			imgsTexturas[1] = gcnew Bitmap("textura1.png");
			imgsTexturas[2] = gcnew Bitmap("fondo2.png");
			imgsTexturas[3] = gcnew Bitmap("textura2.png");
			imgsTexturas[4] = gcnew Bitmap("fondo3.png");
			imgsTexturas[5] = gcnew Bitmap("textura3.png");
			imgsTexturas[6] = gcnew Bitmap("fondo4.png");
			imgsTexturas[7] = gcnew Bitmap("textura4.png");
			imgsTexturas[8] = gcnew Bitmap("FondoMenuCompleto.png");



			//volver transparente las imagenes
			for each (Bitmap^ img in imgsTorres)
			{
				img->MakeTransparent(img->GetPixel(0, 0));
			}
			for each (Bitmap^ img in imgsEnemigos)
			{
				img->MakeTransparent(img->GetPixel(0, 0));
			}
			//ocultar los botones de menu al inicio
			btnIniciarJuego->Visible = false;
			btnCargarJuego->Visible = false;
			btnInstrucciones->Visible = false;
			btnCreditos->Visible = false; 
			btnSalida->Visible = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Panel^  panel2;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  timerJuego;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Bitmap^ imgTorre;
		//CMapa *oMapa;
		COleadas * oOleada;
		//ArrEnemigos * enemigos;
		CNivel* oNivel;
		CJuego* oJuego;
		CTorre* TorreClick;
		time_t hora_inicial;
		CTorre* TorreSeleccionada;
		array<Bitmap^>^ imgsTorres;
		array<Bitmap^>^ imgsTexturas;
		int contDtorre;
		array<Bitmap^>^ imgsEnemigos;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  grpbxDetaTorre;

	private: System::Windows::Forms::GroupBox^  grpbx_Torres;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  lbl_puntaje;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  gpb_nivel;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lbl_Dinero;
	private: System::Windows::Forms::Label^  lbl_vidas;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Timer^  timerMenu;
private: System::Windows::Forms::Button^  btnSalida;
private: System::Windows::Forms::Button^  btnCreditos;
private: System::Windows::Forms::Button^  btnInstrucciones;
private: System::Windows::Forms::Button^  btnCargarJuego;
private: System::Windows::Forms::Button^  btnIniciarJuego;
private: System::Windows::Forms::Button^  btnPausa;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button1;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnSalida = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnCargarJuego = (gcnew System::Windows::Forms::Button());
			this->btnIniciarJuego = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->grpbxDetaTorre = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->grpbx_Torres = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->btnPausa = (gcnew System::Windows::Forms::Button());
			this->lbl_puntaje = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->gpb_nivel = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_vidas = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Dinero = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerMenu = (gcnew System::Windows::Forms::Timer(this->components));
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->grpbxDetaTorre->SuspendLayout();
			this->grpbx_Torres->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->gpb_nivel->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoSize = true;
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->btnSalida);
			this->panel1->Controls->Add(this->btnCreditos);
			this->panel1->Controls->Add(this->btnInstrucciones);
			this->panel1->Controls->Add(this->btnCargarJuego);
			this->panel1->Controls->Add(this->btnIniciarJuego);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(547, 637);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			this->panel1->MouseHover += gcnew System::EventHandler(this, &Form1::panel1_MouseHover);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseMove);
			// 
			// btnSalida
			// 
			this->btnSalida->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSalida.BackgroundImage")));
			this->btnSalida->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSalida->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalida->Location = System::Drawing::Point(183, 437);
			this->btnSalida->Name = L"btnSalida";
			this->btnSalida->Size = System::Drawing::Size(179, 36);
			this->btnSalida->TabIndex = 4;
			this->btnSalida->Text = L"Salir";
			this->btnSalida->UseVisualStyleBackColor = true;
			this->btnSalida->Click += gcnew System::EventHandler(this, &Form1::btnSalida_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreditos.BackgroundImage")));
			this->btnCreditos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(183, 383);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(179, 36);
			this->btnCreditos->TabIndex = 3;
			this->btnCreditos->Text = L"Créditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &Form1::btnCreditos_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnInstrucciones.BackgroundImage")));
			this->btnInstrucciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(183, 332);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(179, 36);
			this->btnInstrucciones->TabIndex = 2;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = true;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &Form1::btnInstrucciones_Click);
			// 
			// btnCargarJuego
			// 
			this->btnCargarJuego->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCargarJuego.BackgroundImage")));
			this->btnCargarJuego->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCargarJuego->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnCargarJuego->Location = System::Drawing::Point(183, 278);
			this->btnCargarJuego->Name = L"btnCargarJuego";
			this->btnCargarJuego->Size = System::Drawing::Size(179, 36);
			this->btnCargarJuego->TabIndex = 1;
			this->btnCargarJuego->Text = L"Cargar Juego";
			this->btnCargarJuego->UseVisualStyleBackColor = true;
			this->btnCargarJuego->Click += gcnew System::EventHandler(this, &Form1::btnCargarJuego_Click);
			// 
			// btnIniciarJuego
			// 
			this->btnIniciarJuego->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnIniciarJuego.BackgroundImage")));
			this->btnIniciarJuego->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnIniciarJuego->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnIniciarJuego->Location = System::Drawing::Point(183, 227);
			this->btnIniciarJuego->Name = L"btnIniciarJuego";
			this->btnIniciarJuego->Size = System::Drawing::Size(179, 36);
			this->btnIniciarJuego->TabIndex = 0;
			this->btnIniciarJuego->Text = L"Iniciar Juego";
			this->btnIniciarJuego->UseVisualStyleBackColor = true;
			this->btnIniciarJuego->Click += gcnew System::EventHandler(this, &Form1::btnIniciarJuego_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel2->Controls->Add(this->grpbxDetaTorre);
			this->panel2->Controls->Add(this->grpbx_Torres);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel2->Location = System::Drawing::Point(565, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(197, 637);
			this->panel2->TabIndex = 1;
			// 
			// grpbxDetaTorre
			// 
			this->grpbxDetaTorre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->grpbxDetaTorre->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"grpbxDetaTorre.BackgroundImage")));
			this->grpbxDetaTorre->Controls->Add(this->button5);
			this->grpbxDetaTorre->Controls->Add(this->button4);
			this->grpbxDetaTorre->Controls->Add(this->label9);
			this->grpbxDetaTorre->Controls->Add(this->label8);
			this->grpbxDetaTorre->Controls->Add(this->label7);
			this->grpbxDetaTorre->Controls->Add(this->label6);
			this->grpbxDetaTorre->Controls->Add(this->label5);
			this->grpbxDetaTorre->Controls->Add(this->label4);
			this->grpbxDetaTorre->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpbxDetaTorre->Location = System::Drawing::Point(4, 534);
			this->grpbxDetaTorre->Name = L"grpbxDetaTorre";
			this->grpbxDetaTorre->Size = System::Drawing::Size(190, 100);
			this->grpbxDetaTorre->TabIndex = 5;
			this->grpbxDetaTorre->TabStop = false;
			this->grpbxDetaTorre->Text = L"Detalle de Torre";
			this->grpbxDetaTorre->Enter += gcnew System::EventHandler(this, &Form1::groupBox4_Enter);
			// 
			// button5
			// 
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(118, 55);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(66, 39);
			this->button5->TabIndex = 7;
			this->button5->Text = L"SELL";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(118, 18);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(66, 34);
			this->button4->TabIndex = 6;
			this->button4->Text = L"UP";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Location = System::Drawing::Point(75, 65);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(16, 16);
			this->label9->TabIndex = 5;
			this->label9->Text = L"  ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Location = System::Drawing::Point(75, 42);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(12, 16);
			this->label8->TabIndex = 4;
			this->label8->Text = L" ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Location = System::Drawing::Point(75, 20);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(12, 16);
			this->label7->TabIndex = 3;
			this->label7->Text = L" ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(12, 65);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 16);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Velocidad:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 42);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 16);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Ataque:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 16);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Tipo:";
			// 
			// grpbx_Torres
			// 
			this->grpbx_Torres->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->grpbx_Torres->AutoSize = true;
			this->grpbx_Torres->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"grpbx_Torres.BackgroundImage")));
			this->grpbx_Torres->Controls->Add(this->button2);
			this->grpbx_Torres->Location = System::Drawing::Point(4, 184);
			this->grpbx_Torres->Name = L"grpbx_Torres";
			this->grpbx_Torres->Size = System::Drawing::Size(190, 344);
			this->grpbx_Torres->TabIndex = 4;
			this->grpbx_Torres->TabStop = false;
			this->grpbx_Torres->Text = L"Torres";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(6, 19);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ataque";
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox2.BackgroundImage")));
			this->groupBox2->Controls->Add(this->button8);
			this->groupBox2->Controls->Add(this->button6);
			this->groupBox2->Controls->Add(this->button7);
			this->groupBox2->Controls->Add(this->btnPausa);
			this->groupBox2->Controls->Add(this->lbl_puntaje);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->gpb_nivel);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(0, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(197, 178);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Jugador";
			// 
			// button6
			// 
			this->button6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button6->Location = System::Drawing::Point(91, 133);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(90, 39);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Guardar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// btnPausa
			// 
			this->btnPausa->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPausa.BackgroundImage")));
			this->btnPausa->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPausa->Location = System::Drawing::Point(10, 133);
			this->btnPausa->Name = L"btnPausa";
			this->btnPausa->Size = System::Drawing::Size(75, 39);
			this->btnPausa->TabIndex = 5;
			this->btnPausa->Text = L"Pausar";
			this->btnPausa->UseVisualStyleBackColor = true;
			this->btnPausa->Click += gcnew System::EventHandler(this, &Form1::btnPausa_Click);
			// 
			// lbl_puntaje
			// 
			this->lbl_puntaje->AutoSize = true;
			this->lbl_puntaje->BackColor = System::Drawing::Color::Transparent;
			this->lbl_puntaje->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_puntaje->Location = System::Drawing::Point(91, 17);
			this->lbl_puntaje->Name = L"lbl_puntaje";
			this->lbl_puntaje->Size = System::Drawing::Size(51, 16);
			this->lbl_puntaje->TabIndex = 4;
			this->lbl_puntaje->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(13, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Puntaje total :";
			// 
			// gpb_nivel
			// 
			this->gpb_nivel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->gpb_nivel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gpb_nivel.BackgroundImage")));
			this->gpb_nivel->Controls->Add(this->lbl_vidas);
			this->gpb_nivel->Controls->Add(this->label3);
			this->gpb_nivel->Controls->Add(this->button3);
			this->gpb_nivel->Controls->Add(this->label1);
			this->gpb_nivel->Controls->Add(this->lbl_Dinero);
			this->gpb_nivel->Location = System::Drawing::Point(10, 52);
			this->gpb_nivel->Name = L"gpb_nivel";
			this->gpb_nivel->Size = System::Drawing::Size(178, 75);
			this->gpb_nivel->TabIndex = 2;
			this->gpb_nivel->TabStop = false;
			this->gpb_nivel->Text = L"Nivel 1";
			// 
			// lbl_vidas
			// 
			this->lbl_vidas->AutoSize = true;
			this->lbl_vidas->BackColor = System::Drawing::Color::Transparent;
			this->lbl_vidas->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_vidas->Location = System::Drawing::Point(94, 32);
			this->lbl_vidas->Name = L"lbl_vidas";
			this->lbl_vidas->Size = System::Drawing::Size(51, 16);
			this->lbl_vidas->TabIndex = 4;
			this->lbl_vidas->Text = L"label4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Vidas :";
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(6, 48);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(165, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Siguiente Oleada >>";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dinero :";
			// 
			// lbl_Dinero
			// 
			this->lbl_Dinero->AutoSize = true;
			this->lbl_Dinero->BackColor = System::Drawing::Color::Transparent;
			this->lbl_Dinero->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Dinero->Location = System::Drawing::Point(94, 16);
			this->lbl_Dinero->Name = L"lbl_Dinero";
			this->lbl_Dinero->Size = System::Drawing::Size(51, 16);
			this->lbl_Dinero->TabIndex = 1;
			this->lbl_Dinero->Text = L"label2";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(190, 100);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Debug";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(6, 19);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Leer Mapa";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timerJuego
			// 
			this->timerJuego->Tick += gcnew System::EventHandler(this, &Form1::timerJuego_Tick);
			// 
			// timerMenu
			// 
			this->timerMenu->Tick += gcnew System::EventHandler(this, &Form1::timerMenu_Tick);
			// 
			// button7
			// 
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(52, 552);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(66, 34);
			this->button7->TabIndex = 6;
			this->button7->Text = L"UP";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.BackgroundImage")));
			this->button8->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(52, 589);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(66, 39);
			this->button8->TabIndex = 7;
			this->button8->Text = L"SELL";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(774, 661);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ClientSizeChanged += gcnew System::EventHandler(this, &Form1::Form1_ClientSizeChanged);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->grpbxDetaTorre->ResumeLayout(false);
			this->grpbxDetaTorre->PerformLayout();
			this->grpbx_Torres->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->gpb_nivel->ResumeLayout(false);
			this->gpb_nivel->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int contadorTiempo;
	private: System::Void timerJuego_Tick(System::Object^  sender, System::EventArgs^  e)
			 {
				
		//pre logica
				 oJuego->BajarVida(oNivel->MoverOlas());
				 oNivel->moverBalas(this->ClientRectangle);
		//parte gráfica
				Graphics ^gr = panel1->CreateGraphics();
				 BufferedGraphicsContext ^espacio=BufferedGraphicsManager::Current;
				 BufferedGraphics ^buffer=espacio->Allocate(gr,this->ClientRectangle);
				 //ingresar los dibujar debajo
				// oMapa->DibujarMapa(imgsTexturas,buffer->Graphics,panel1->ClientRectangle);
				 oNivel->dibujarMapa(imgsTexturas,buffer->Graphics,panel1->ClientRectangle);
				 if(oOleada==nullptr && oNivel->getmapa()->getbloqueAnchoalto()->GetX()>16){
					oOleada = new COleadas(oNivel->getmapa());//temporal
					oNivel->agregarOleada(oOleada);
				 }
				// enemigos->dibujarEnemigo(imgsEnemigos,buffer->Graphics);
				// oOleada->DibujarOleada(imgsEnemigos, buffer->Graphics);
				 oNivel->dibujarOlas(imgsEnemigos,buffer->Graphics);
				 //oNivel->dibujarOlas(buffer->Graphics);
				 //dibujarTorres
				 oNivel->dibujarTorres(imgsTorres,buffer->Graphics);
				 oNivel->dibujarBalas(buffer->Graphics);
				 //dibujar torre al seleccionar del panel
				 if (TorreSeleccionada!= nullptr)
					 if (!TorreSeleccionada->GetPuestoEnElSuelo()){
						 
						 buffer->Graphics->DrawRectangle(Pens::LightGreen, seleccion);
						// TorreSeleccionada->DibujarTorre(buffer->Graphics);
						  TorreSeleccionada->Dibujar(imgsTorres[0],buffer->Graphics);
						  TorreSeleccionada->DibujarRango(buffer->Graphics);
					 }

				 //fin de los dibujar
				 buffer->Render(gr);
				 delete buffer;
				 delete espacio;
				 delete gr;
				
				 //parte lógica
				//time_t hora_crear_enemigo = time(NULL);
				//if (difftime(hora_crear_enemigo, hora_inicial) > 1)
				 int periodoDeSalidaDeEnemigo=20; //recuerda que eso ya esta definido en una clase creo que en enemigos salen muy rapido creo
				 //parece que debe estar debajo de dibujar mapa porque sino no tomara los valores
				
//					
				// oOleada->AparecerTropa(contadorTiempo,oMapa);
				 oNivel->MostrarTropa(0,contadorTiempo);
		
				 oJuego->TotalDinero+=oNivel->Colisiona();
				 
				 //oOleada->moverTropas(oMapa);
				  oNivel->dispararTorres();
				//oNivel->MoverOlas(oMapa);

				  //actualizar labels
				  if(Convert::ToInt32(lbl_Dinero->Text) != oJuego->TotalDinero)
				  lbl_Dinero->Text=L"" + oJuego->TotalDinero;

				  if(Convert::ToInt32(lbl_vidas->Text) != oJuego->TotalVidas)
					  if(oJuego->TotalVidas>0)
					  lbl_vidas->Text=L"" + oJuego->TotalVidas;
					  else{
					  lbl_vidas->Text=L"0";
					  timerJuego->Stop();
					  btnPausa->Enabled=false;
					  MessageBox::Show("Juego Terminado :(");
					  timerMenu->Start();
					  }
				 contadorTiempo++;
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 FILE * archive = fopen("mapa1.txt","r+t");
				 if(archive!= nullptr){
				 oNivel->getmapa()->LeerdeArchivo(archive);
				 fclose(archive);
				 }
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	//
	
	//setear imagen en el boton
	//button2->Image = "";
	this->Text = "Pequeño Detalle";
	this->WindowState=FormWindowState::Maximized;
	this->button2->BackgroundImage = imgsTorres[0];
	
		 }
private: 
	bool pausaLocal ;
	System::Void Form1_ClientSizeChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ClientSize.Width == 0 || ClientSize.Height == 0)
		{
			timerJuego->Stop();
			pausaLocal = true;
		}
	else if(pausaLocal){
		pausaLocal = false;
		timerJuego->Start();
	}else{
	button1_Click(nullptr,nullptr);
	//if (oOleada == nullptr)
	//iniciar timer de menu
	groupBox1->Visible = false;
	timerMenu->Start();
		btnIniciarJuego->Visible = true;
		btnCargarJuego->Visible = true;
		btnInstrucciones->Visible = true;
		btnCreditos->Visible = true;
		btnSalida->Visible = true;
		//timerJuego->Start();
	
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	//suponiendo que la torre este 100
	int precio_torre = 100;
	if (precio_torre > oJuego->TotalDinero){ 
		MessageBox::Show("No hay plata mijo!");
	}
	else{
		if (TorreSeleccionada == nullptr){
		
				oJuego->TotalDinero -= precio_torre;
	
			//TODO se debe quitar el dinero solo cuando la torre esta posicionada
			lbl_Dinero->Text = gcnew String("" + oJuego->TotalDinero);
			//crear torre
			CPunto* p = new CPunto(-500,-500);
			CPunto* ISA = new CPunto(0, 0); //indice sprite actual
			CPunto* ISM = new CPunto(0, 0); //indice sprite max (por si se mueve)
			CCirculo* c = new CCirculo(p, oNivel->getmapa()->getbloqueAnchoalto()->GetX() / 2);
			TorreSeleccionada = new CTorreAtaque(p, "", ISA, ISM, new CPunto(oNivel->getmapa()->getbloqueAnchoalto()->GetX(), oNivel->getmapa()->getbloqueAnchoalto()->GetY()*2), c, 100, 200, 1, 1, false);
			TorreSeleccionada->SetCantIxS(new CPunto(1,1));//setea la cantidad de imagenes tiene el sprite ancho x alto
			TorreSeleccionada->SetISMin(new CPunto(0, 0));
		}
	}
}
private: System::Void panel1_MouseHover(System::Object^  sender, System::EventArgs^  e) {

}
private: 
	Rectangle seleccion;
	System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (TorreSeleccionada != nullptr){
		if (!TorreSeleccionada->GetPuestoEnElSuelo()){
			//dibujar debajo del mouse
			seleccion.Width = oNivel->getmapa()->getbloqueAnchoalto()->GetX();
			seleccion.Height = oNivel->getmapa()->getbloqueAnchoalto()->GetX();
			seleccion.X = (e->X/(int)oNivel->getmapa()->getbloqueAnchoalto()->GetX()) *seleccion.Width;
			seleccion.Y = (e->Y/(int)oNivel->getmapa()->getbloqueAnchoalto()->GetY())* seleccion.Height;
			
			//TorreSeleccionada->SetPosicion(new CPunto(e->X, e->Y));
			TorreSeleccionada->SetPosicion(new CPunto(seleccion.X, seleccion.Y-seleccion.Width));
			TorreSeleccionada->GetColision()->SetPosicion(new CPunto(seleccion.X, seleccion.Y));
			
		}
	}
}
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	TorreClick = oNivel->BuscarTorreSeleccionada(e->X, e->Y);
	if (TorreClick!= nullptr)
	{
		String^s = gcnew String(TorreClick->GetTipoEscrito().c_str());
		label7->Text = s;
		label8->Text = gcnew String("" + TorreClick->GetAtaque());
		label9->Text = gcnew String("" + TorreClick->GetVelocidad());
	}
	else
	{
		
		TorreClick = nullptr;
		label7->Text = "";
		label8->Text = "";
		label9->Text = "";
	}
	
	if (TorreSeleccionada != nullptr){
		//cuando haga click ubicar la ubicacion en el mapa 
		int posX=seleccion.X / seleccion.Width;
		int posY = seleccion.Y / seleccion.Height;
		//valida que el cuadro este FREE
		if (oNivel->getmapa()->GetCaracterDelMapa(posX, posY) == (int)CMapa::MAPA::FREE){
			//crearla
			CPunto *p = new CPunto(seleccion.X, (seleccion.Y)-seleccion.Height);
			CPunto *q = new CPunto(seleccion.X, (seleccion.Y));
			CTorreAtaque *nuevaTorre = new CTorreAtaque(p, "", new CPunto(0, 0)
				, new CPunto(2, 0), new CPunto(seleccion.Width, (seleccion.Height)*2), new CCirculo(q, seleccion.Width/2.f), 100, 200, 1, 1, true);
			nuevaTorre->SetCantIxS(new CPunto(2, 1));
			nuevaTorre->SetISMin(new CPunto(0, 0));
			//agregarla al arreglo de torres
			oNivel->CrearTorre(nuevaTorre);
			//bloquear el lugar en el mapa
			oNivel->getmapa()->BloquearCaracterMapa(posX,posY);
		
			//eliminar torreseleccionada para poder usarla nuevamente una vez creada
			delete TorreSeleccionada;
			TorreSeleccionada = nullptr;
		}
	}
	//preguntar si se hace click sobre una torre
}
private: System::Void groupBox4_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	//suponinedo que el precio es 50
	
	
	if (TorreClick != nullptr)
	{
		oJuego->TotalDinero += TorreClick->GetPrecioVenta();
		lbl_Dinero->Text = gcnew String("" + oJuego->TotalDinero);
		oNivel->getmapa()->DesBloquearCaracterMapa(TorreClick->GetColision()->GetCentro()->GetX() / seleccion.Width, TorreClick->GetColision()->GetCentro()->GetY() / seleccion.Height);
    	oNivel->EliminarTorre(TorreClick);
		TorreClick = nullptr;
		label7->Text = "";
		label8->Text = "";
		label9->Text = "";
	}
}
private: System::Void timerMenu_Tick(System::Object^  sender, System::EventArgs^  e) {
	Graphics ^gr = panel1->CreateGraphics();
	BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
	BufferedGraphics ^buffer = espacio->Allocate(gr, this->ClientRectangle);

	buffer->Graphics->DrawImage(imgsTexturas[8], 0, 0, panel1->Width, panel1->Height);
	buffer->Render(gr);
	delete buffer;
	delete espacio;
	delete gr;
}
private: System::Void btnIniciarJuego_Click(System::Object^  sender, System::EventArgs^  e) {
	btnIniciarJuego->Visible = false;
	btnCargarJuego->Visible = false;
	btnInstrucciones->Visible = false;
	btnCreditos->Visible = false;
	btnSalida->Visible = false;
	btnPausa->Visible = true;

	btnIniciarJuego->Enabled = false;
	btnCargarJuego->Enabled = false;
	btnInstrucciones->Enabled = false;
	btnCreditos->Enabled = false;
	btnSalida->Enabled = false;
	
	btnPausa->Enabled = true;
	panel2->Visible=true;
	timerMenu->Stop();
	timerJuego->Start();
	oNivel->dibujarMapa(imgsTexturas,panel1->CreateGraphics(), panel1->ClientRectangle);
}
private: System::Void btnCargarJuego_Click(System::Object^  sender, System::EventArgs^  e) {
			 FILE * archivo = fopen("defensa1.dat","r+b");
			 if(archivo != nullptr)
			 {
				 oNivel->LeerNiveldeArchivo(archivo);
			 }
			 fclose(archivo);
}
private: System::Void btnInstrucciones_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("LA DEFENSA\nINSTRUCCIONES\nEs una emocionante experiencia, en constante cambio. Puedes construir una o varias torres fortificadas y muy estables, gastar los recursos en manejar tus cuatro tipos de torres, mejorar sus habilidades y vencer a tus oponentes.");
}
private: System::Void btnCreditos_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Trabajo de Estructuras de Datos y Algoritmos\n    2014-02\nHecho por:\nSteve Valentin\nErik Medina");
}
private: System::Void btnSalida_Click(System::Object^  sender, System::EventArgs^  e) {
	if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show("Estas seguro de salir?", "Pequeno Detalle", MessageBoxButtons::YesNo))
		Application::Exit();
}
		 bool ParaPausa;
private: System::Void btnPausa_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ParaPausa == false)
	{
		timerJuego->Stop();
		//timerJuego->Enabled = false;
		//panel2->Visible=false;
		 
		//pausaLocal = false;
		ParaPausa = true;
		btnPausa->Text = L"Reanudar";
		timerMenu->Start();
		 
		btnInstrucciones->Visible = true;
		btnCreditos->Visible = true;		 
		btnSalida->Visible = true;


		btnInstrucciones->Enabled = true;
		btnCreditos->Enabled = true;
		btnSalida->Enabled = true;

		for each (Button^ x in grpbx_Torres->Controls)
		{
			x->Enabled=false;
		}
		for each (Control^ x in grpbxDetaTorre->Controls)
		{
			if(x->GetType()== System::Windows::Forms::Button::typeid)
				((Button^)x)->Enabled=false;
		}

	}
	else
	{
		timerMenu->Stop(); 
		ParaPausa = false;
		btnPausa->Text = L"Pausa"; 

		btnInstrucciones->Visible = false;
		btnCreditos->Visible = false;
		btnSalida->Visible = false;


		btnInstrucciones->Enabled = false;
		btnCreditos->Enabled = false;
		btnSalida->Enabled = false;

		for each (Button^ x in this->grpbx_Torres->Controls)
		{
			x->Enabled=true;
		}
		for each (Control^ x in grpbxDetaTorre->Controls)
		{
			if(x->GetType()== System::Windows::Forms::Button::typeid)
				x->Enabled=true;
		}

		timerJuego->Start();
	}

}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 FILE * archivo = fopen("defensa1.dat","w+b");
			 if(archivo != nullptr)
			 {
				 oNivel->guardarArchivo(archivo);
			 }
			 fclose(archivo);
		 }
};
}
