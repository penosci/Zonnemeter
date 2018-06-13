xmlhttp = new XMLHttpRequest();
xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        serverdata2 = JSON.parse(this.responseText);
        serverdata2.map(function(e) {
          e[0] = new Date(e[0]);
        });
        google.charts.load('current', {packages: ['corechart', 'line']});
        google.charts.setOnLoadCallback(drawBasic1);
    }
};
xmlhttp.open("GET", "php/get_data_power.php", true);
xmlhttp.send();


  // Load the Visualization API and the corechart package.


function drawBasic1() {

    var data = new google.visualization.DataTable();
    data.addColumn('date', 'X');
    data.addColumn('number', 'Solar power');

    data.addRows(serverdata2);

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

xmlhttp = new XMLHttpRequest();
xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        serverdata1 = JSON.parse(this.responseText);
        serverdata1.map(function(e) {
          e[0] = new Date(e[0]);
        });
        google.charts.load('current', {packages: ['corechart', 'line']});
        google.charts.setOnLoadCallback(drawBasic2);
    }
};
xmlhttp.open("GET", "php/get_data_temp.php", true);
xmlhttp.send();


  // Load the Visualization API and the corechart package.


function drawBasic2() {

    var data = new google.visualization.DataTable();
    data.addColumn('date', 'X');
    data.addColumn('number', 'Temperature');

    data.addRows(serverdata1);

    var options = {
      hAxis: {
        title: 'Time'
      },
      vAxis: {
        title: 'W/m2'
      }
    };

    var chart = new google.visualization.LineChart(document.getElementById('chart_div2'));

    chart.draw(data, options);

}

//obj = { "table":"customers", "limit":10 };
//dbParam = JSON.stringify(obj);
