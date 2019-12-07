var dirLoc = window.location.pathname;
var dir = dirLoc.substring(0, dirLoc.lastIndexOf('/'));

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
			alert('Error');
		}
	};
	commentpic.send('name='+fileName+'&comment='+comment);
}

function resetPic() {
	canvasElementPic.style.display = "none";
	canvasElementSti.style.display = "none";
	videoPlayer.style.display = "block";

	stickers = false;
}

function capturePic() {
	videoPlayer.style.display = "none";
	canvasElementPic.style.display = "block";
	canvasElementSti.style.display = "block";
	const context = canvasElementPic.getContext("2d");
	context.drawImage(videoPlayer, 0, 0, canvasElementPic.width, canvasElementPic.height);

	videoPlayer.srcObject.getVideoTracks().forEach(track => {});
	stickers = true;
}

// function savePic() {
// 	canvasElementPic.style.display = "none";
// 	canvasElementSti.style.display = "none";
// 	videoPlayer.style.display = "block";
// 	stickers = false;

// 	let picture = canvasElementPic.toDataURL();
// 	let stickers = canvasElementSti.toDataURL();

// 	fetch("./api/save_image.php", {
// 		method: "post",
// 		body: JSON.stringify({ data: picture, stickers: stickers })
// 	})
// 	.then(res => res.json())
// 	.then(data => {
// 		if (data.success) {
// 			data.path = imageLoc+data.path;
// 			let newImage = createImage(
// 				data.path,
// 				"new image",
// 				"new image",
// 				width,
// 				height,
// 				"masked"
// 			);
// 			console.log(newImage);
// 			let tilt = -(20 + 60 * Math.random());
// 			newImage.style.transform = "rotate(" + tilt + "deg)";
// 			zIndex++;
// 			newImage.style.zIndex = zIndex;
// 			newImages.appendChild(newImage);
// 			canvasElementPic.classList.add("masked");
// 		}
// 	})
// 	.catch(error => console.log(error));
// }

function savePic() {
	canvasElementPic.style.display = "none";
	canvasElementSti.style.display = "none";
	videoPlayer.style.display = "block";
	stickers = false;

	let picture = canvasElementPic.toDataURL();
	let sticker = canvasElementSti.toDataURL();

	savepic = new XMLHttpRequest();

	savepic.open('post', './api/save_image.php');
	savepic.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
	savepic.onload = function() {
		if (savepic.status === 200) {
			alert('success');
		} else {
			alert('failure');
		}
	}
	savepic.send('pic='+sticker+'&sti='+sticker);
}

function cute(id) {
	if (stickers === true) {
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
	}
}