<?php
// --- Inclure les bibliotheques
require 'jpgraph/jpgraph.php';
require 'jpgraph/jpgraph_pie.php';
// --- Creer le conteneur graphique
$graph = new PieGraph(600,500);
// --- Creer le diagramme a secteurs
$donnees= array(56,46,30);
$legende= array('Lumiere','Chauffage','Ventilation');

$camembert=new PiePlot($donnees);
$camembert->SetLegends($legende);
// --- Ajouter le camembert au graphique
$graph->Add($camembert);

// --- Choisir le format d'image
$graph->img->SetImgFormat("png");

// --- Envoyer au navigateur
$graph->Stroke();

?>
