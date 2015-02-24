namespace Taquin
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label2 = new System.Windows.Forms.Label();
            this.panelTableau = new System.Windows.Forms.Panel();
            this.buttonMelanger = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.textNbLignes = new System.Windows.Forms.TextBox();
            this.textNbColonnes = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(130, 45);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(14, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "X";
            // 
            // panelTableau
            // 
            this.panelTableau.AutoSize = true;
            this.panelTableau.Location = new System.Drawing.Point(56, 83);
            this.panelTableau.Name = "panelTableau";
            this.panelTableau.Size = new System.Drawing.Size(311, 231);
            this.panelTableau.TabIndex = 3;
            // 
            // buttonMelanger
            // 
            this.buttonMelanger.Location = new System.Drawing.Point(224, 42);
            this.buttonMelanger.Name = "buttonMelanger";
            this.buttonMelanger.Size = new System.Drawing.Size(143, 23);
            this.buttonMelanger.TabIndex = 4;
            this.buttonMelanger.Text = "Choisir l\'image et mélanger";
            this.buttonMelanger.UseVisualStyleBackColor = true;
            this.buttonMelanger.Click += new System.EventHandler(this.buttonMelanger_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog";
            // 
            // textNbLignes
            // 
            this.textNbLignes.Location = new System.Drawing.Point(56, 42);
            this.textNbLignes.Name = "textNbLignes";
            this.textNbLignes.Size = new System.Drawing.Size(68, 20);
            this.textNbLignes.TabIndex = 5;
            // 
            // textNbColonnes
            // 
            this.textNbColonnes.Location = new System.Drawing.Point(150, 42);
            this.textNbColonnes.Name = "textNbColonnes";
            this.textNbColonnes.Size = new System.Drawing.Size(68, 20);
            this.textNbColonnes.TabIndex = 6;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(53, 26);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(90, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Nombre de cases";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(485, 378);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textNbColonnes);
            this.Controls.Add(this.textNbLignes);
            this.Controls.Add(this.buttonMelanger);
            this.Controls.Add(this.panelTableau);
            this.Controls.Add(this.label2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Panel panelTableau;
        private System.Windows.Forms.Button buttonMelanger;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.TextBox textNbLignes;
        private System.Windows.Forms.TextBox textNbColonnes;
        private System.Windows.Forms.Label label1;

    }
}

