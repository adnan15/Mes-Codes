<?php

namespace SC\PlateformBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class VuesController extends Controller
{
    public function indexAction()
    {
        return $this->render('SCPlateformBundle:Vues:index.html.twig');
    }
}
