xmlhttp = new XMLHttpRequest();
xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        serverdata = JSON.parse(this.responseText);
        serverdata.map(function(e) {
          e[0] = new Date(e[0]);
        });
    }
};
xmlhttp.open("GET", "php/get_data.php", true);
xmlhttp.send();


  // Load the Visualization API and the corechart package.
  google.charts.load('current', {packages: ['corechart', 'line']});
  google.charts.setOnLoadCallback(drawBasic);

function drawBasic() {

    var data = new google.visualization.DataTable();
    data.addColumn('date', 'X');
    data.addColumn('number', 'Temperature');
    data.addColumn('number', 'Solar power');

    data.addRows(serverdata);

    var options = {
      hAxis: {
        title: 'Time'
      },
      vAxis: {
        title: 'W/m2'
      }
    };

    var chart = new google.visualization.LineChart(document.getElementById('chart_div'));

    chart.draw(data, options);

}

//obj = { "table":"customers", "limit":10 };
//dbParam = JSON.stringify(obj);
