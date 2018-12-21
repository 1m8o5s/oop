#pragma once
#include <cstring>
namespace laboratorna8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для new_component
	/// </summary>
	public ref class new_component : public System::Windows::Forms::Form
	{
	public:
		new_component(char* type)
		{
			InitializeComponent();
			label1->Text = gcnew String("Додати ") + gcnew String(type);
			if (!strcmp(type, "Visitor")) {
				Bitmap^ bmp = gcnew Bitmap(282, 126);
				Graphics^ g = Graphics::FromImage(bmp); // холст для рисования
				pictureBox1->Image = bmp; // закрепление к pictureBox

				Bitmap^ image1; // фото загрузки в pictureBox

				image1 = gcnew Bitmap("./images/visitors.jpg"); // инициализация файл с фото

				pictureBox1->Image = image1;
			}
			else if (!strcmp(type, "Cassa")) {
				Bitmap^ bmp = gcnew Bitmap(282, 126);
				Graphics^ g = Graphics::FromImage(bmp); // холст для рисования
				pictureBox1->Image = bmp; // закрепление к pictureBox

				Bitmap^ image1; // фото загрузки в pictureBox

				image1 = gcnew Bitmap("./images/cassa.jpg"); // инициализация файл с фото

				pictureBox1->Image = image1;
			}
			else if (!strcmp(type, "Concert")) {
				Bitmap^ bmp = gcnew Bitmap(500, 500);
				Graphics^ g = Graphics::FromImage(bmp); // холст для рисования
				pictureBox1->Image = bmp; // закрепление к pictureBox

				Bitmap^ image1; // фото загрузки в pictureBox

				image1 = gcnew Bitmap("./images/concert.jpeg"); // инициализация файл с фото

				pictureBox1->Image = image1;
			}
			else if (!strcmp(type, "Singer")) {
				Bitmap^ bmp = gcnew Bitmap(282, 126);
				Graphics^ g = Graphics::FromImage(bmp); // холст для рисования
				pictureBox1->Image = bmp; // закрепление к pictureBox

				Bitmap^ image1; // фото загрузки в pictureBox

				image1 = gcnew Bitmap("./images/singer.jpg"); // инициализация файл с фото

				pictureBox1->Image = image1;
			}
			else if (!strcmp(type, "Security manager")) {
				Bitmap^ bmp = gcnew Bitmap(500, 500);
				Graphics^ g = Graphics::FromImage(bmp); // холст для рисования
				pictureBox1->Image = bmp; // закрепление к pictureBox

				Bitmap^ image1; // фото загрузки в pictureBox

				image1 = gcnew Bitmap("./images/security.jpg"); // инициализация файл с фото

				pictureBox1->Image = image1;
			}
			else if (!strcmp(type, "Singer manager")) {
				Bitmap^ bmp = gcnew Bitmap(282, 126);
				Graphics^ g = Graphics::FromImage(bmp); // холст для рисования
				pictureBox1->Image = bmp; // закрепление к pictureBox

				Bitmap^ image1; // фото загрузки в pictureBox

				image1 = gcnew Bitmap("./images/singer_manager.jpg"); // инициализация файл с фото

				pictureBox1->Image = image1;
			}
			else if (!strcmp(type, "Club manager")) {
				Bitmap^ bmp = gcnew Bitmap(282, 126);
				Graphics^ g = Graphics::FromImage(bmp); // холст для рисования
				pictureBox1->Image = bmp; // закрепление к pictureBox

				Bitmap^ image1; // фото загрузки в pictureBox

				image1 = gcnew Bitmap("./images/club_manager.jpg"); // инициализация файл с фото

				pictureBox1->Image = image1;
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~new_component()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(new_component::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(66, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Виберіть файл, де описа";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(69, 83);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 49);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Додати";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(76, 34);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, 138);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(282, 126);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"cassa.jpg");
			this->imageList1->Images->SetKeyName(1, L"club_manager.jpg");
			this->imageList1->Images->SetKeyName(2, L"concert.jpeg");
			this->imageList1->Images->SetKeyName(3, L"security_manager.jpg");
			this->imageList1->Images->SetKeyName(4, L"security_manager_triggered.jpg");
			this->imageList1->Images->SetKeyName(5, L"singer.jpg");
			this->imageList1->Images->SetKeyName(6, L"singer_manager.jpg");
			this->imageList1->Images->SetKeyName(7, L"visitors.jpg");
			// 
			// new_component
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 277);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"new_component";
			this->Text = L"new_component";
			this->Load += gcnew System::EventHandler(this, &new_component::new_component_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void new_component_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
