<?php

namespace SC\PlateformBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class DefaultController extends Controller
{
    public function indexAction()
    {
        return $this->render('SCPlateformBundle:Default:index.html.twig');
    }
}
