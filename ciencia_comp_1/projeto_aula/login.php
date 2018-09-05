<?php
//session_start();
 
if(isset($_SESSION['logado']) &&  $_SESSION['logado'] == 'SIM'):
	header("Location: home.html");
endif;
?>
<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" type="text/css" href="_css/style2.css" />
    <link rel="stylesheet" type="text/css" href="_css/login.css" />
    <title>Login</title>
</head>

<body>
<div class="container">
    <div class="topo">
        <div class="logo">
            <a href="index2.html">
                <img src="_img/logo.png" />
            </a>
        </div>
        <nav>
            <li>
                <a href="index2.html">Home</a>
                <a href="#">Login</a>
                <a href="#">Contato</a>
            </li>
        </nav>
    </div>
    <div id="login-alert">
        <span id="mensagem"></span>
    </div>   
    <div class="banner">
        <div class="login-box">
            <div class="input">
              <form method="POST" id="login_form" action="index.php" role="form">
                  <fieldset>
                      <legend>Login Usuario</legend>
                      <h6>Usuario: <input type="text" name="txNome"  size="30" maxlength="30" placeholder="Digite seu o nome do usuario ou email"></h6>
                      <h6>Senha: <input type="password" name="txSenha" size="30" maxlength="30" placeholder="Digite sua senha"></h6>
                      <button type="button" name="btenviar" id="btenviar">Enviar</button>
                  </fieldset>
              </form>
                <h6>Não é cadastrado? <a href="cadastro.html"> Cadastre-se grátis!</a></h6>
            </div>

        </div>
    </div>
    <footer>

    </footer>
</div>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>  
<script src="_js/custom.js"></script>
</body>

</html>