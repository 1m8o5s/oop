#pragma once
#include "miniworld_definition.h"
#include "new_component.h"
#include "remove_component.h"
#include "ManageCassa.h"
#include "ManageVisitor.h"
#include "ManageSinger.h"
namespace laboratorna8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ World2D
	/// </summary>
	public ref class World2D : public System::Windows::Forms::Form
	{
	public:
		World2D(bool new_, char* file)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			if (new_) {
				this->world = new MiniWorld();

			}
			else {
				this->world = new MiniWorld();
			}
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~World2D()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: MiniWorld* world;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  visitorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  manageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cassaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  concertToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  singerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clubManagerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  singerManagerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  securityManagerToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem1;

	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem2;

	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem3;

	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem4;

	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  manageCassaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem5;

	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  manageSingerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem6;

	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem6;
	private: System::Windows::Forms::ToolStripMenuItem^  expelVisitorToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(World2D::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->visitorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cassaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->concertToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->singerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clubManagerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageCassaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->singerManagerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageSingerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->securityManagerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->expelVisitorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->visitorToolStripMenuItem,
					this->cassaToolStripMenuItem, this->concertToolStripMenuItem, this->singerToolStripMenuItem, this->clubManagerToolStripMenuItem,
					this->singerManagerToolStripMenuItem, this->securityManagerToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(531, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// visitorToolStripMenuItem
			// 
			this->visitorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newToolStripMenuItem,
					this->removeToolStripMenuItem, this->manageToolStripMenuItem
			});
			this->visitorToolStripMenuItem->Name = L"visitorToolStripMenuItem";
			this->visitorToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->visitorToolStripMenuItem->Text = L"Visitor";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &World2D::newToolStripMenuItem_Click);
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->removeToolStripMenuItem->Text = L"Remove";
			this->removeToolStripMenuItem->Click += gcnew System::EventHandler(this, &World2D::removeToolStripMenuItem_Click);
			// 
			// manageToolStripMenuItem
			// 
			this->manageToolStripMenuItem->Name = L"manageToolStripMenuItem";
			this->manageToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->manageToolStripMenuItem->Text = L"Manage";
			this->manageToolStripMenuItem->Click += gcnew System::EventHandler(this, &World2D::manageToolStripMenuItem_Click);
			// 
			// cassaToolStripMenuItem
			// 
			this->cassaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->newToolStripMenuItem1,
					this->removeToolStripMenuItem1
			});
			this->cassaToolStripMenuItem->Name = L"cassaToolStripMenuItem";
			this->cassaToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->cassaToolStripMenuItem->Text = L"Cassa";
			// 
			// newToolStripMenuItem1
			// 
			this->newToolStripMenuItem1->Name = L"newToolStripMenuItem1";
			this->newToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->newToolStripMenuItem1->Text = L"New";
			this->newToolStripMenuItem1->Click += gcnew System::EventHandler(this, &World2D::newToolStripMenuItem1_Click);
			// 
			// removeToolStripMenuItem1
			// 
			this->removeToolStripMenuItem1->Name = L"removeToolStripMenuItem1";
			this->removeToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->removeToolStripMenuItem1->Text = L"Remove";
			this->removeToolStripMenuItem1->Click += gcnew System::EventHandler(this, &World2D::removeToolStripMenuItem1_Click);
			// 
			// concertToolStripMenuItem
			// 
			this->concertToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->newToolStripMenuItem2,
					this->removeToolStripMenuItem2
			});
			this->concertToolStripMenuItem->Name = L"concertToolStripMenuItem";
			this->concertToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->concertToolStripMenuItem->Text = L"Concert";
			// 
			// newToolStripMenuItem2
			// 
			this->newToolStripMenuItem2->Name = L"newToolStripMenuItem2";
			this->newToolStripMenuItem2->Size = System::Drawing::Size(180, 22);
			this->newToolStripMenuItem2->Text = L"New";
			this->newToolStripMenuItem2->Click += gcnew System::EventHandler(this, &World2D::newToolStripMenuItem2_Click);
			// 
			// removeToolStripMenuItem2
			// 
			this->removeToolStripMenuItem2->Name = L"removeToolStripMenuItem2";
			this->removeToolStripMenuItem2->Size = System::Drawing::Size(180, 22);
			this->removeToolStripMenuItem2->Text = L"Remove";
			this->removeToolStripMenuItem2->Click += gcnew System::EventHandler(this, &World2D::removeToolStripMenuItem2_Click);
			// 
			// singerToolStripMenuItem
			// 
			this->singerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->newToolStripMenuItem3,
					this->removeToolStripMenuItem3
			});
			this->singerToolStripMenuItem->Name = L"singerToolStripMenuItem";
			this->singerToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->singerToolStripMenuItem->Text = L"Singer";
			// 
			// newToolStripMenuItem3
			// 
			this->newToolStripMenuItem3->Name = L"newToolStripMenuItem3";
			this->newToolStripMenuItem3->Size = System::Drawing::Size(180, 22);
			this->newToolStripMenuItem3->Text = L"New";
			this->newToolStripMenuItem3->Click += gcnew System::EventHandler(this, &World2D::newToolStripMenuItem3_Click);
			// 
			// removeToolStripMenuItem3
			// 
			this->removeToolStripMenuItem3->Name = L"removeToolStripMenuItem3";
			this->removeToolStripMenuItem3->Size = System::Drawing::Size(180, 22);
			this->removeToolStripMenuItem3->Text = L"Remove";
			this->removeToolStripMenuItem3->Click += gcnew System::EventHandler(this, &World2D::removeToolStripMenuItem3_Click);
			// 
			// clubManagerToolStripMenuItem
			// 
			this->clubManagerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newToolStripMenuItem4,
					this->removeToolStripMenuItem4, this->manageCassaToolStripMenuItem
			});
			this->clubManagerToolStripMenuItem->Name = L"clubManagerToolStripMenuItem";
			this->clubManagerToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->clubManagerToolStripMenuItem->Text = L"Club Manager";
			// 
			// newToolStripMenuItem4
			// 
			this->newToolStripMenuItem4->Name = L"newToolStripMenuItem4";
			this->newToolStripMenuItem4->Size = System::Drawing::Size(180, 22);
			this->newToolStripMenuItem4->Text = L"New";
			this->newToolStripMenuItem4->Click += gcnew System::EventHandler(this, &World2D::newToolStripMenuItem4_Click);
			// 
			// removeToolStripMenuItem4
			// 
			this->removeToolStripMenuItem4->Name = L"removeToolStripMenuItem4";
			this->removeToolStripMenuItem4->Size = System::Drawing::Size(180, 22);
			this->removeToolStripMenuItem4->Text = L"Remove";
			this->removeToolStripMenuItem4->Click += gcnew System::EventHandler(this, &World2D::removeToolStripMenuItem4_Click);
			// 
			// manageCassaToolStripMenuItem
			// 
			this->manageCassaToolStripMenuItem->Name = L"manageCassaToolStripMenuItem";
			this->manageCassaToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->manageCassaToolStripMenuItem->Text = L"Manage Cassa";
			this->manageCassaToolStripMenuItem->Click += gcnew System::EventHandler(this, &World2D::manageCassaToolStripMenuItem_Click);
			// 
			// singerManagerToolStripMenuItem
			// 
			this->singerManagerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newToolStripMenuItem5,
					this->removeToolStripMenuItem5, this->manageSingerToolStripMenuItem
			});
			this->singerManagerToolStripMenuItem->Name = L"singerManagerToolStripMenuItem";
			this->singerManagerToolStripMenuItem->Size = System::Drawing::Size(102, 20);
			this->singerManagerToolStripMenuItem->Text = L"Singer Manager";
			// 
			// newToolStripMenuItem5
			// 
			this->newToolStripMenuItem5->Name = L"newToolStripMenuItem5";
			this->newToolStripMenuItem5->Size = System::Drawing::Size(180, 22);
			this->newToolStripMenuItem5->Text = L"New";
			this->newToolStripMenuItem5->Click += gcnew System::EventHandler(this, &World2D::newToolStripMenuItem5_Click);
			// 
			// removeToolStripMenuItem5
			// 
			this->removeToolStripMenuItem5->Name = L"removeToolStripMenuItem5";
			this->removeToolStripMenuItem5->Size = System::Drawing::Size(180, 22);
			this->removeToolStripMenuItem5->Text = L"Remove";
			this->removeToolStripMenuItem5->Click += gcnew System::EventHandler(this, &World2D::removeToolStripMenuItem5_Click);
			// 
			// manageSingerToolStripMenuItem
			// 
			this->manageSingerToolStripMenuItem->Name = L"manageSingerToolStripMenuItem";
			this->manageSingerToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->manageSingerToolStripMenuItem->Text = L"Manage Singer";
			this->manageSingerToolStripMenuItem->Click += gcnew System::EventHandler(this, &World2D::manageSingerToolStripMenuItem_Click);
			// 
			// securityManagerToolStripMenuItem
			// 
			this->securityManagerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newToolStripMenuItem6,
					this->removeToolStripMenuItem6, this->expelVisitorToolStripMenuItem
			});
			this->securityManagerToolStripMenuItem->Name = L"securityManagerToolStripMenuItem";
			this->securityManagerToolStripMenuItem->Size = System::Drawing::Size(111, 20);
			this->securityManagerToolStripMenuItem->Text = L"Security Manager";
			// 
			// newToolStripMenuItem6
			// 
			this->newToolStripMenuItem6->Name = L"newToolStripMenuItem6";
			this->newToolStripMenuItem6->Size = System::Drawing::Size(180, 22);
			this->newToolStripMenuItem6->Text = L"New";
			this->newToolStripMenuItem6->Click += gcnew System::EventHandler(this, &World2D::newToolStripMenuItem6_Click);
			// 
			// removeToolStripMenuItem6
			// 
			this->removeToolStripMenuItem6->Name = L"removeToolStripMenuItem6";
			this->removeToolStripMenuItem6->Size = System::Drawing::Size(180, 22);
			this->removeToolStripMenuItem6->Text = L"Remove";
			this->removeToolStripMenuItem6->Click += gcnew System::EventHandler(this, &World2D::removeToolStripMenuItem6_Click);
			// 
			// expelVisitorToolStripMenuItem
			// 
			this->expelVisitorToolStripMenuItem->Name = L"expelVisitorToolStripMenuItem";
			this->expelVisitorToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->expelVisitorToolStripMenuItem->Text = L"Expel Visitor";
			this->expelVisitorToolStripMenuItem->Click += gcnew System::EventHandler(this, &World2D::expelVisitorToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(531, 327);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// World2D
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(531, 355);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"World2D";
			this->Text = L"World2D";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void newToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	new_component ^ nc = gcnew new_component("Cassa");
	nc->Show();
}
private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	new_component ^ nc = gcnew new_component("Visitor");
	nc->Show();
}
private: System::Void removeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	remove_component ^ rc = gcnew remove_component("Visitor");
	rc->Show();
}
private: System::Void manageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ManageVisitor ^ mv = gcnew ManageVisitor();
}
private: System::Void removeToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	remove_component ^ rc = gcnew remove_component("Concert");
	rc->Show();
}
private: System::Void newToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	new_component ^ nc = gcnew new_component("Concert");
	nc->Show();
}
private: System::Void removeToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	remove_component ^ rc = gcnew remove_component("Singer");
	rc->Show();
}
private: System::Void newToolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) {
	new_component ^ nc = gcnew new_component("Singer");
	nc->Show();
}
private: System::Void removeToolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) {
	ManageCassa ^ mc = gcnew ManageCassa();
	mc->Show();
}
private: System::Void newToolStripMenuItem4_Click(System::Object^  sender, System::EventArgs^  e) {
	new_component ^ nc = gcnew new_component("Club manager");
	nc->Show();
}
private: System::Void removeToolStripMenuItem4_Click(System::Object^  sender, System::EventArgs^  e) {
	remove_component ^ rc = gcnew remove_component("Club manager");
	rc->Show();
}
private: System::Void manageCassaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ManageSinger ^ ms = gcnew ManageSinger();
}
private: System::Void newToolStripMenuItem5_Click(System::Object^  sender, System::EventArgs^  e) {
	new_component ^ nc = gcnew new_component("Singer manager");
	nc->Show();
}

private: System::Void removeToolStripMenuItem5_Click(System::Object^  sender, System::EventArgs^  e) {
	remove_component ^ rc = gcnew remove_component("Singer manager");
	rc->Show();
}
private: System::Void manageSingerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void newToolStripMenuItem6_Click(System::Object^  sender, System::EventArgs^  e) {
	new_component ^ nc = gcnew new_component("Security manager");
	nc->Show();
}

private: System::Void removeToolStripMenuItem6_Click(System::Object^  sender, System::EventArgs^  e) {
	remove_component ^ rc = gcnew remove_component("Security manager");
	rc->Show();
}
private: System::Void expelVisitorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

}
};
}
