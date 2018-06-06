$(document).ready(function(){
  var current_page = "dashboard";
  $(".site_content").load('php/dashboard.php');

  $(".dashboard_link").click(function(){
    current_page = "dashboard";
    $(".site_content").load('php/dashboard.php');

  });
  $(".week_graph_link").click(function(){
    current_page = "week_graph";
    $(".site_content").load('php/week_graph.php');

  });
  window.setInterval(function(){
    $(".site_content").load('php/dashboard.php');
    //console.log(current_page);
    if(current_page = "dashboard") {
      //console.log("dash reload");
    }
  }, 10000);
});
