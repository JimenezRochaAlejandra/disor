namespace FormCesar
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador requerida.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén utilizando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben eliminar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido del método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtTextoPlano = new System.Windows.Forms.TextBox();
            this.txtTextoAnalizado = new System.Windows.Forms.TextBox();
            this.lblTxtCifrado = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.inputDesplazamiento = new System.Windows.Forms.NumericUpDown();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtTransposicion = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.inputGrupos = new System.Windows.Forms.NumericUpDown();
            this.txtGrupos = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.inputDesplazamiento)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.inputGrupos)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 64);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 16);
            this.label1.TabIndex = 0;
            this.label1.Text = "Texto:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Monotype Corsiva", 14.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(286, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(143, 22);
            this.label2.TabIndex = 1;
            this.label2.Text = "CIFRADO CÉSAR";
            // 
            // txtTextoPlano
            // 
            this.txtTextoPlano.Location = new System.Drawing.Point(63, 43);
            this.txtTextoPlano.Multiline = true;
            this.txtTextoPlano.Name = "txtTextoPlano";
            this.txtTextoPlano.Size = new System.Drawing.Size(630, 69);
            this.txtTextoPlano.TabIndex = 2;
            this.txtTextoPlano.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // txtTextoAnalizado
            // 
            this.txtTextoAnalizado.Location = new System.Drawing.Point(9, 42);
            this.txtTextoAnalizado.Multiline = true;
            this.txtTextoAnalizado.Name = "txtTextoAnalizado";
            this.txtTextoAnalizado.ReadOnly = true;
            this.txtTextoAnalizado.Size = new System.Drawing.Size(201, 174);
            this.txtTextoAnalizado.TabIndex = 4;
            // 
            // lblTxtCifrado
            // 
            this.lblTxtCifrado.AutoSize = true;
            this.lblTxtCifrado.Location = new System.Drawing.Point(15, 272);
            this.lblTxtCifrado.Name = "lblTxtCifrado";
            this.lblTxtCifrado.Size = new System.Drawing.Size(0, 13);
            this.lblTxtCifrado.TabIndex = 5;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(6, 16);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(109, 16);
            this.label4.TabIndex = 6;
            this.label4.Text = "Desplazamiento:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.inputDesplazamiento);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.txtTextoAnalizado);
            this.groupBox1.Location = new System.Drawing.Point(13, 119);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(216, 222);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "César";
            // 
            // inputDesplazamiento
            // 
            this.inputDesplazamiento.Location = new System.Drawing.Point(122, 16);
            this.inputDesplazamiento.Minimum = new decimal(new int[] {
            26,
            0,
            0,
            -2147483648});
            this.inputDesplazamiento.Name = "inputDesplazamiento";
            this.inputDesplazamiento.Size = new System.Drawing.Size(88, 20);
            this.inputDesplazamiento.TabIndex = 7;
            this.inputDesplazamiento.ValueChanged += new System.EventHandler(this.inputDesplazamiento_ValueChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txtTransposicion);
            this.groupBox2.Location = new System.Drawing.Point(236, 119);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(222, 222);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Transposición inversa";
            // 
            // txtTransposicion
            // 
            this.txtTransposicion.Location = new System.Drawing.Point(7, 20);
            this.txtTransposicion.Multiline = true;
            this.txtTransposicion.Name = "txtTransposicion";
            this.txtTransposicion.ReadOnly = true;
            this.txtTransposicion.Size = new System.Drawing.Size(209, 196);
            this.txtTransposicion.TabIndex = 0;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.txtGrupos);
            this.groupBox3.Controls.Add(this.inputGrupos);
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Location = new System.Drawing.Point(465, 119);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(234, 222);
            this.groupBox3.TabIndex = 9;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Transposición inversa agrupada";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(6, 23);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(55, 16);
            this.label3.TabIndex = 0;
            this.label3.Text = "Grupos:";
            // 
            // inputGrupos
            // 
            this.inputGrupos.Location = new System.Drawing.Point(68, 23);
            this.inputGrupos.Name = "inputGrupos";
            this.inputGrupos.Size = new System.Drawing.Size(160, 20);
            this.inputGrupos.TabIndex = 1;
            // 
            // txtGrupos
            // 
            this.txtGrupos.Location = new System.Drawing.Point(6, 49);
            this.txtGrupos.Multiline = true;
            this.txtGrupos.Name = "txtGrupos";
            this.txtGrupos.ReadOnly = true;
            this.txtGrupos.Size = new System.Drawing.Size(222, 167);
            this.txtGrupos.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(711, 353);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.lblTxtCifrado);
            this.Controls.Add(this.txtTextoPlano);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.inputDesplazamiento)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.inputGrupos)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtTextoPlano;
        private System.Windows.Forms.TextBox txtTextoAnalizado;
        private System.Windows.Forms.Label lblTxtCifrado;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.NumericUpDown inputDesplazamiento;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox txtTransposicion;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtGrupos;
        private System.Windows.Forms.NumericUpDown inputGrupos;
    }
}

