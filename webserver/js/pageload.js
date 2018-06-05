$(document).ready(function(){
  var current_page = "dashboard";
  $(".site_content").load('php/dashboard.php');

  $(".dashboard_link").click(function(){
    current_page
    $(".site_content").load('php/dashboard.php');

  });
  window.setInterval(reload_dash, 10000);
});

function reload_dash() {
  $(".site_content").load('php/dashboard.php');
  console.log("dash reload");
}
