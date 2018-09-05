<?php
    $host="127.0.0.1";
    $port=3306;
    $socket="";
    $user="root";
    $password="raostrovski01";
    $dbname="projectmedicenter";

    $con = new mysqli($host, $user, $password, $dbname, $port, $socket)
    	or die ('Erro na conexão com o banco de dados: ' . mysqli_connect_error());
?>