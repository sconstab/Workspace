var dirLoc = window.location.pathname;
var dir = dirLoc.substring(0, dirLoc.lastIndexOf('/'));
var capture = false;
var stickers = false;
var upload = false;

function deletePic(fileName) {
	var r = confirm("Are you sure you want to delete this pic");
	if (r == true) {
		deletepic = new XMLHttpRequest();
		
		deletepic.open('POST', 'delete.php');
		deletepic.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
		deletepic.onload = function() {
			if (deletepic.status === 200) {
				location.reload();
			} else {
				alert('Error');
			}
		};
		deletepic.send('file='+fileName);
	}
}

function likePic(fileName) {
	likepic = new XMLHttpRequest();
	
	likepic.open('POST', 'like.php');
	likepic.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
	likepic.onload = function() {
		if (likepic.status === 200) {
			console.log(this.responseText);
			location.reload();
		} else {
			alert('Error');
		}
	};
	likepic.send('name='+fileName);
}

function commentPic(fileName) {
	document.getElementById(fileName).submit();
	var comment = document.getElementById("comment"+fileName).value;
	commentpic = new XMLHttpRequest();
	
	commentpic.open('POST', 'comment.php');
	commentpic.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
	commentpic.onload = function() {
		if (commentpic.status === 200) {
			location.reload();
		} else {
			console.log('Error');
		}
	};
	commentpic.send('name='+fileName+'&comment='+comment);
}

function resetPic() {
	canvasElementPic.style.display = "none";
	canvasElementSti.style.display = "none";
	videoPlayer.style.display = "block";
	
	const context = canvasElementSti.getContext("2d");
	context.clearRect(0, 0, canvasElementSti.width, canvasElementSti.height);
	stickers = false;
	capture = false;
	upload = false;
}

function capturePic() {
	videoPlayer.style.display = "none";
	canvasElementPic.style.display = "block";
	canvasElementSti.style.display = "block";
	const context = canvasElementPic.getContext("2d");
	context.drawImage(videoPlayer, 0, 0, canvasElementPic.width, canvasElementPic.height);
	
	capture = true;
}

function savePic(type) {
	let picture = encodeURIComponent(canvasElementPic.toDataURL().replace("data:image/png;base64,", ""));
	let sticker = encodeURIComponent(canvasElementSti.toDataURL().replace("data:image/png;base64,", ""));
	let picked = encodeURIComponent(pickedImage.toDataURL().replace("data:image/png;base64,", ""));
	
	savepic = new XMLHttpRequest();
	
	savepic.open('post', './api/save_image.php');
	savepic.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
	savepic.onload = function() {
		if (savepic.status === 200) {
			let newImage = createImage(
				"./uploads/images/"+savepic.responseText,
				"new image",
				"new image",
				width,
				height,
				"masked"
				);
				console.log(newImage);
				let tilt = -(20 + 60 * Math.random());
				newImage.style.transform = "rotate("+tilt+"deg)";
				zIndex++;
				newImage.style.zIndex = zIndex;
				newImages.appendChild(newImage);
				canvasElementPic.classList.add("masked");
				newImages.style.display = "block";
			} else {
				alert("Error");
			}
		}
		// alert(type+"   "+capture);
		if (capture === true || upload === true) {
			if (type === 'camera') {
				savepic.send('pic='+picture+'&sti='+sticker);
			} else if (type === 'upload') {
				savepic.send('pic='+picked);
				document.getElementById("image-picker").value = "";
			}
		}
		
		const context = canvasElementSti.getContext("2d");
		context.clearRect(0, 0, canvasElementSti.width, canvasElementSti.height);
		canvasElementPic.style.display = "none";
		canvasElementSti.style.display = "none";
		videoPlayer.style.display = "block";
		stickers = false;
		capture = false;
		upload = false;
	}
	
	function cute(id) {
		if (capture === true) {
			const context = canvasElementSti.getContext("2d");
			const image = document.getElementById(id);
			
			if (id === "cuteCat") {
				context.drawImage(image, 0, 0, 50, 50);
			} else if (id === "cutePed") {
				context.drawImage(image, 270, 0, 50, 50);
			} else if (id === "cuteDog") {
				context.drawImage(image, 270, 190, 50, 50);
			} else if (id === "cuteOtt") {
				context.drawImage(image, 0, 190, 50, 50);
			} else {
				alert("Error sticker does not exist");
			}
			stickers = true;
		}
	}
	
function uploadPic() {
	var files = imagePicker.files;
	if (files.length === 0) {return;}
	var file = files[0];
	if (file.type !== '' && !file.type.match('image.*')) {return;}
	
	var reader = new FileReader();
	reader.onload = function(event) {
		var dataUri = event.target.result,
		context = pickedImage.getContext("2d"),
		img     = new Image();
		
		img.onload = function() {
			var ratio = Math.min (pickedImage.width/img.width, pickedImage.height/img.height);
			context.drawImage(img, 0, 0, img.width, img.height, 0, 0, img.width*ratio, img.height*ratio);
			pickedWra.style.display = "block";
			pickedImage.style.display = "block";
		};
		img.src = dataUri;
	};
	
	reader.onerror = function(event) {
		console.error("File could not be read! Code " + event.target.error.code);
	};
	
	reader.readAsDataURL(file);
	upload = true;
}

var endless = {
	page: 0,
	hasMore: true,
	proceed: true,

	load: function(type) {
		if (endless.proceed && endless.hasMore) {
			endless.proceed = false;
			
			data = new FormData();
			nextPg = endless.page + 1;
			loading = document.getElementById("page-loading");
			data.append('page', nextPg);
			data.append('type', type);
			
			// loading.style.display = "block";
			
			loadContent = new XMLHttpRequest();
			loadContent.open('POST', 'load.php');
			loadContent.onload = function() {
				if (loadContent.responseText == "END") {
					loading.innerHTML = "END";
					endless.hasMore = false;
					console.log("END");
				} else {
					var el = document.createElement('div');
					el.id = "content";
					el.innerHTML = this.response;
					document.getElementById("page-content").appendChild(el);
					// loading.style.display = "none";
					endless.page = nextPg;
					endless.proceed = true;
				}
				console.log(type);
			};
			loadContent.send(data);
		}
	},

	listenFeed: function() {
		var body = document.body,
		html = document.documentElement;

		var height = Math.max( body.scrollHeight, body.offsetHeight, html.clientHeight, html.scrollHeight, html.offsetHeight );
		var offset = document.documentElement.scrollTop + window.innerHeight + 5;
		if (offset > height) {endless.load("feed");}
	},

	listenGallery: function() {
		var body = document.body,
		html = document.documentElement;

		var height = Math.max( body.scrollHeight, body.offsetHeight, html.clientHeight, html.scrollHeight, html.offsetHeight );
		var offset = document.documentElement.scrollTop + window.innerHeight + 5;
		if (offset > height) {endless.load("gallery");}
	}
};

function forgotPass() {
	forgotPass = new XMLHttpRequest();

	console.log("hi");
	forgotPass.open('POST', 'forgotPass.php');
	forgotPass.onload = function() {
		console.log(forgotPass.responseText);
	}
	forgotPass.send("dir="+dir);
}

function resetPassword() {
	document.getElementById('reset-pass').submit();
	var pass = document.getElementById('resetPass').value();
	var repass = document.getElementById('resetRepass').value();

	if (pass === repass) {
		resetPass = new XMLHttpRequest();
	} else {
	}
}

function test() {
	alert("hi");
}