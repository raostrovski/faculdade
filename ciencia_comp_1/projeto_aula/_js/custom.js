$('document').ready(function(){
    $("#btenviar").click(function(){
        var data = $("#login_form").serialize();
            
        $.ajax({
            type : 'POST',
            url  : 'index.php',
            data : data,
            dataType: 'json',
            beforeSend: function()
            {	
                $("#btneviar").html('Validando ...');
            },
            success :  function(response){						
                if(response.codigo == "1"){	
                    $("#btneviar").html('Entrar');
                    window.location.href = "home.html";
                }
                else{			
                    $("#btenviar").html('Entrar');
                    $("#login-alert").css('display', 'block')
                    $("#mensagem").html('<strong>Erro! </strong>' + response.mensagem);
                }
            }
        });
    });
});