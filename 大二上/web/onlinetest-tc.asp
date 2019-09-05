<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html"/>
    <title></title>
    <meta charset="utf-8" />
   
    <script type="text/javascript">
    	function transDateHMS(date) {
		    var minute = date.getMinutes();
		    if (minute < 10) minute = "0" + minute;
		    var second = date.getSeconds();
		    if (second < 10) second = "0" + second;
		    return date.getHours() + ":" + minute + ":" + second;
		}

		function transDateMS(date) {
		    var minute = date.getMinutes();
		    if (minute < 10) minute = "0" + minute;
		    var second = date.getSeconds();
		    if (second < 10) second = "0" + second;
		    return minute + ":" + second;
		}

		var total = 15 * 60000;
		var dateBegin
		var now
		var usedTime;

		function clock() {
		    now = new Date();

		    used = now - dateBegin;
		    usedTime = new Date(used);
		    document.getElementById("usedTime").innerHTML = transDateMS(usedTime);

		    var leftTime = new Date(total - used + 500);
		    document.getElementById("leftTime").innerHTML = transDateMS(leftTime);

		    document.getElementById("curTime").innerHTML = transDateHMS(now);

		    var hour = now.getHours();
		    var s = document.getElementById("greeting");
		    if (hour < 12) s.innerHTML = "Good Morning";
		    else if (hour < 18) s.innerHTML = "Good afternoon";
		    else s.innerHTML = "Good evening";
		}

function add(obj)
{
    var score = 0;
    var chk1 = document.getElementsByName("1");
    for(var i=0;i<chk1.length;i++){
        if(chk1[i].checked){
            if(chk1[i].value == "D"){
                score += 1;
                break;
            }
        }
    }

    var chk2 = document.getElementById("2");
  var index2 = chk2.selectedIndex;
  var value2 = chk2.options[index2].value;

 if(value2 == "C"){
                score += 1;          
}



    
    var chk3 = document.getElementsByName("3");
    for(var i=0;i<chk3.length;i++){
		if(chk[i].checked){
            if(chk3[i].value == "B" )
			{
				score += 1
                break;
            }
        }
	}
    var chk4 = document.getElementsByName("4");
    if(chk4[0].value == "B"){
        score += 1;
    }
    document.getElementById("UserScore").value = score

    alert("Your scores is " + score);


}







</script>
</head>
<body background = "/BG.jpg">
	<h1>对BIT了解程度的调查</h1>
    <p id="greeting"></p>
	<p ><%=request.form("UserName") %></p>
	<div style="border: 1px solid">
        <p>已用时长: <span id="usedTime"></span></p>
        <p>剩余时长: <span id="leftTime"></span></p>
        <p>当前时间: <span id="curTime"></span></p>
    </div>
	<script type="text/javascript">
        dateBegin = new Date();
        clock();
        window.setInterval(clock, 1000);
    </script>
	<form onsubmit="add()" action="../Documents/Tencent Files/1622637293/FileRecv/result.asp" method="post">
<ol>


<li><p>北京理工大学建校时间：</p>
<input type = "checkbox" name = "3" value="A"/>A. 1939</br>
<input type = "checkbox" name = "3" value="B"/>B. 1940</br>
<input type = "checkbox" name = "3" value="C"/>C. 1949</br>
<input type = "checkbox" name = "3" value="D"/>D. 1953</br></li>




<li><p>北京理工大学现任校长：</br></p>
<p>A. 王越</br>B. 胡海岩</br>C. 匡镜明</br>D. 徐特立</br></p>
<p>你的答案是 <input type = "test" name = "4" maxlength = "1" size = "1"/>.</br></p>
</li>

<li><p>下面哪个不是北京理工大学前身？</p>
<select id = "2">
<option selected="selected" value = "">请选择你的答案</option>
<option name = "22" value="A">A.延安自然科学院</option>
<option name = "22" value="B">B.北京工业大学</option>
<option name = "22" value="C">C. 北京钢铁学院</option>
<option name = "22" value="D">D. 华北大学工学院</option>
</select></li>


<li><p>北京理工大学共有几个校区？</p>
<input type = "radio" name = "1" value="A"/>A. 3</br>
<input type = "radio" name = "1" value="B"/>B. 4</br>
<input type = "radio" name = "1" value="C"/>C. 5</br>
<input type = "radio" name = "1" value="D"/>D. 6</br></li>






</ol>

<input type="submit" value="提交" />
<input type="hidden" name="UserName" value="<%=request.form("UserName") %>">
		<input type="hidden" name="UserScore" id="UserScore" value="">
	</form>
</body>
</html>
