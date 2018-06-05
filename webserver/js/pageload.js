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
  window.setInterval(reload_dash(current_page), 10000);
});

function reload_dash(current_page) {
  $(".site_content").load('php/dashboard.php');
  if(current_page = "dashboard") {
    console.log("dash reload");
  }

}
