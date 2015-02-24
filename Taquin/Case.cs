using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

namespace Taquin
{
    class Case
    {
        public PictureBox imageCase { get; set; }
        public Point positionCourante{get;set;}
        public Point bonnePosition { get; set; }
        public bool isEmptyBox { get; set; }

        public Case(PictureBox imageCase, Point positionCourante, Point bonnePosition)
        {
            this.imageCase = imageCase;
            this.positionCourante = positionCourante;
            this.bonnePosition = bonnePosition;
        }
        public Case()
        {
        }
        public bool isBienPlace()
        {
            return positionCourante.X == bonnePosition.X && positionCourante.Y == bonnePosition.Y;
        }
    }
}
