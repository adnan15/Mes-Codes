using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;



namespace Taquin
{
    public partial class Form1 : Form
    {
        private Image image;
        private int nbLignes, nbColonnes;
        private Case[,] tableauCases;
        private Boolean isEmptyBox;

        public Form1()
        {
            InitializeComponent();

        }
        private void Decouper()
        {
            int nvllecol = nbColonnes * 100;
            int nvllelig = nbLignes * 100;
            Bitmap imageComplete = new Bitmap(image,nvllecol,nvllelig);
            tableauCases = new Case[nbColonnes, nbLignes];
            for (int i = 0; i < nbColonnes; i++)
            {
                for (int j = 0; j < nbLignes; j++)
                {
                    tableauCases[i, j] = new Case();
                    tableauCases[i, j].bonnePosition = new Point(i, j);
                    tableauCases[i, j].imageCase = new PictureBox();
                    Bitmap imagePartielle = new Bitmap(100, 100);
                    if (i == 0 && j == 0)
                    {
                        tableauCases[i, j].isEmptyBox = true;
                    }
                    else
                    {
                        tableauCases[i, j].isEmptyBox = false;
                    }
                    tableauCases[i, j].imageCase.Location = new Point(i * 100, j * 100);
                    tableauCases[i, j].positionCourante = new Point(i, j);
                    tableauCases[i, j].imageCase.Size = new Size(100, 100);
                    tableauCases[i, j].imageCase.BorderStyle = BorderStyle.Fixed3D;
                    if (tableauCases[i, j].isEmptyBox == false)
                    {
                        for (int col = (i * 100); col < ((i + 1) * 100); col++)
                        {
                            for (int lig = (j * 100); lig < ((j + 1) * 100); lig++)
                            {
                                Color couleur = imageComplete.GetPixel(col, lig);
                                int coll = col - (i * 100);
                                int ligg = lig - (j * 100);
                                imagePartielle.SetPixel(coll, ligg, couleur);
                                tableauCases[i, j].imageCase.Image = imagePartielle;
                            }

                        }
                    }
                    else
                    {
                        tableauCases[i, j].imageCase.Image = null;
                    }
                  panelTableau.Controls.Add(tableauCases[i, j].imageCase);
                    
                }
            }
            

        }
        private Boolean bienMelanger()
        {
            Boolean verf=false;
            for (int i = 0; i < nbColonnes; i++)
            {
                for (int j = 0; j < nbLignes; j++)
                {
                    if (tableauCases[i, j].isBienPlace())
                    {
                        verf = true;
                    }
                    else
                    {
                        verf = false;
                    }
                }
            }
            return verf;

        }

        private void Melanger()
        {
           Random r = new Random();
           List<int> list = new List<int>();
           List<int> list1 = new List<int>();
            
            for (int i = 0; i < nbColonnes; i++)
            {
                list.Insert(r.Next(0, list.Count+1), i);
            }
            for (int j = 0; j < nbLignes; j++)
            {
                list1.Insert(r.Next(0, list1.Count + 1), j);
            }
            for (int i = 0; i < nbColonnes; i++)
            {
                for (int j = 0; j < nbLignes; j++)
                {
                    tableauCases[i, j].bonnePosition = new Point(i, j);
                    tableauCases[i, j].positionCourante = new Point(list[i], list1[j]);
                    tableauCases[i, j].imageCase.Location = new Point(list[i] * 100, list1[j] * 100);
                }
            }
        }

        private void buttonMelanger_Click(object sender, EventArgs e)
        {
            try
            {
                nbLignes = System.Convert.ToInt32(textNbLignes.Text);
                nbColonnes = System.Convert.ToInt32(textNbColonnes.Text);
                if (nbLignes < 1 || nbColonnes < 1)
                    MessageBox.Show("Le nombre de cases doit être supérieur à 1x1");
                else
                {
                    openFileDialog1 = new OpenFileDialog();
                    openFileDialog1.Title = "Sélectionnez une image";
                    openFileDialog1.FileName = null;
                    openFileDialog1.DefaultExt = "jpg";
                    openFileDialog1.Filter = "Fichier Jpeg (*.jpg |*.jpg|Fichiers Bitmaps(*.bmp)|*.bmp";
                    openFileDialog1.CheckFileExists = true; 
                    if (openFileDialog1.ShowDialog() == DialogResult.OK)
                    {
                        image=(Bitmap)(Image.FromStream(openFileDialog1.OpenFile()));
                        Decouper();
                        Melanger();
                        if (bienMelanger() == true)
                        {
                            Melanger();
                        }
                        AjouterDragDrop();
                    }
                }
            }
            catch(Exception ex)
            {
                System.Console.WriteLine(ex);
                MessageBox.Show("Les parametre de chargement sont incorrectes");
            }
        }

        private void ImageCase_MouseMove(Object sender, MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Left)
            {
               ((PictureBox)sender).DoDragDrop(((Case)(((PictureBox)sender).Tag)), DragDropEffects.Copy);
            }
        }
        private void ImageCase_DragEnter(Object sender, DragEventArgs e)
        {
            Case destination = (Case)(((PictureBox)sender).Tag);
            if (destination.isEmptyBox == true)
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }
        private void ImageCase_DragDrop(object sender, DragEventArgs e)
        {
            Case destination = (Case)(((PictureBox)sender).Tag);
            Case tmp = new Case() ;
            tmp.imageCase=new PictureBox();
            tmp.positionCourante = new Point();
            Case origine=((Case)e.Data.GetData("Taquin.Case"));
            tmp.imageCase.Location = origine.imageCase.Location;
            tmp.positionCourante = origine.positionCourante;
            origine.imageCase.Location = destination.imageCase.Location;
            origine.positionCourante = destination.positionCourante;
            destination.imageCase.Location = tmp.imageCase.Location;
            destination.positionCourante = tmp.positionCourante;
            //label1.Text = origine.bonnePosition.X.ToString() + "," + origine.bonnePosition.Y.ToString();
            //label2.Text = origine.positionCourante.X.ToString() + "," + origine.positionCourante.Y.ToString();
            if (origine.isBienPlace() == true)
            {
                origine.imageCase.Enabled = false;
            }
        }
        private void AjouterDragDrop()
        {
            for (int i = 0; i < nbColonnes; i++)
            {
                for (int j = 0; j < nbLignes; j++)
                {
                    tableauCases[i, j].imageCase.AllowDrop = true;
                    tableauCases[i, j].imageCase.DragDrop += new DragEventHandler(this.ImageCase_DragDrop);
                    tableauCases[i, j].imageCase.DragEnter += new DragEventHandler(this.ImageCase_DragEnter);
                    tableauCases[i, j].imageCase.MouseMove += new MouseEventHandler(this.ImageCase_MouseMove);
                    tableauCases[i, j].imageCase.Tag = tableauCases[i, j];
                    panelTableau.Controls.Add(tableauCases[i, j].imageCase);       
                }
            }
        }
}
}
