using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Tic_tac
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int[,] tab = new int[3, 3] { { 99, 99, 99 }, { 99, 99, 99 }, { 99, 99, 99 } };

        Boolean Letour = false;
        string jeux = "";
        public void tour(Button bt)
        {
            if (Letour == true)
            {
                bt.Text = "X";
                bt.Enabled = false;
                label3.Text = "A Joureur1 de jouer";
                Letour = false;
            }
            else
            {
                bt.Text = "O";
                bt.Enabled = false;
                label3.Text = "A joureur2 de jouer";
                Letour = true;
            }
        }
        public void jouer(Button bt)
        {
            switch (bt.Name)
            {
                case "button1":
                    if (bt.Text == "X") tab[0, 0] = 3;
                    else if (bt.Text == "O") tab[0, 0] = 5;
                    break;
                case "button2":
                    if (bt.Text == "X") tab[0, 1] = 3;
                    else if (bt.Text == "O") tab[0, 1] = 5;
                    break;
                case "button3":
                    if (bt.Text == "X") tab[0, 2] = 3;
                    else if (bt.Text == "O") tab[0, 2] = 5;
                    break;
                case "button4":
                    if (bt.Text == "X") tab[1, 0] = 3;
                    else if (bt.Text == "O") tab[1, 0] = 5;
                    break;
                case "button5":
                    if (bt.Text == "X") tab[1, 1] = 3;
                    else if (bt.Text == "O") tab[1, 1] = 5;
                    break;
                case "button6":
                    if (bt.Text == "X") tab[1, 2] = 3;
                    else if (bt.Text == "O") tab[1, 2] = 5;
                    break;
                case "button7":
                    if (bt.Text == "X") tab[2, 0] = 3;
                    else if (bt.Text == "O") tab[2, 0] = 5;
                    break;
                case "button8":
                    if (bt.Text == "X") tab[2, 1] = 3;
                    else if (bt.Text == "O") tab[2, 1] = 5;
                    break;
                case "button9":
                    if (bt.Text == "X") tab[2, 2] = 3;
                    else if (bt.Text == "O") tab[2, 2] = 5;
                    break;
            }
        }
        public string partie(Button bt)
        {
            if ((tab[0, 0] + tab[0, 1] + tab[0, 2]) == 9 || (tab[0, 0] + tab[1, 1] + tab[2, 2]) == 9 || (tab[0, 0] + tab[1, 0] + tab[2, 0]) == 9 ||
                (tab[0, 1] + tab[1, 1] + tab[2, 1]) == 9 || (tab[0, 2] + tab[1, 2] + tab[2, 2]) == 9 || (tab[0, 2] + tab[1, 1] + tab[2, 0]) == 9 ||
                (tab[1, 0] + tab[1, 1] + tab[1, 2]) == 9 || (tab[2, 0] + tab[2, 1] + tab[2, 2]) == 9)
            {
                label1.Text = "Joueur 2 a gagné";
                jeux = "fin";
            }
            if ((tab[0, 0] + tab[0, 1] + tab[0, 2]) == 15 || (tab[0, 0] + tab[1, 1] + tab[2, 2]) == 15 || (tab[0, 0] + tab[1, 0] + tab[2, 0]) == 15 ||
               (tab[0, 1] + tab[1, 1] + tab[2, 1]) == 15 || (tab[0, 2] + tab[1, 2] + tab[2, 2]) == 15 || (tab[0, 2] + tab[1, 1] + tab[2, 0]) == 15 ||
               (tab[1, 0] + tab[1, 1] + tab[1, 2]) == 15 || (tab[2, 0] + tab[2, 1] + tab[2, 2]) == 15)
            {
                label1.Text = "Joueur 1 a gagné";
                jeux = "fin";
            }
            return jeux;
        }
        public void fParti()
        {
            button1.Enabled = false; button2.Enabled = false; button3.Enabled = false; button4.Enabled = false; button5.Enabled = false;
            button6.Enabled = false; button7.Enabled = false; button8.Enabled = false; button9.Enabled = false;
            label3.Text = "Fin de la Partie";

        }
        private void button_Click(object sender, EventArgs e)
        {
            Button bouton = (Button)sender;
            tour(bouton);
            jouer(bouton);
            partie(bouton);
            if (jeux == "fin")
            {
                fParti();

            }
        }

        private void button11_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            Application.Restart();
        }

    }
}
