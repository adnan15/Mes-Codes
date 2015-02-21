<?php

function HeureL($parm)
{
$heure=date("H:i");
$xml =simplexml_load_file('config.xml');
	for($i=1;$i<10;$i++){
		$plage="P".$i;
		$LumH = ($xml->$parm->LUMIERE->$plage);
		if(isset($LumH)){
		$horaire= $LumH->horaire;
		$keywords = preg_split("/-/", $horaire);	
		if($heure>$keywords[0]&&$heure<$keywords[1]){
		$Presence=$LumH->presence;
		$Seuil=$LumH->seuil;
		$tabL=array($Presence,$Seuil);
		return $tabL ;
		}
		}
	}   
}
function HeureT($parm)
{
$heure=date("H:i");
$xml =simplexml_load_file('config1.xml');
	for($i=1;$i<10;$i++){
		$plage="P".$i;
		$TemH = ($xml->$parm->TEMPERATURE->$plage);
		if(isset($TemH)){
		$horaire= $TemH->horaire;
		$keyH = preg_split("/-/", $horaire);	
		if($heure>$keyH[0]&&$heure<$keyH[1]){
		$degre=$TemH->degre;
		$presence=$TemH->presence;
		$tabT=array($degre,$presence);
		return $tabT ;
		}
		}
}
}
print_r(HeureL("CHAMBRE"));
$heureLu=HeureL("CHAMBRE");
print $heureLu[2];
print HeureL("CHAMBRE")[1];
print_r(HeureT("CHAMBRE"));
print HeureT("CHAMBRE")[1];
?> 
