const videoPlayer = document.querySelector("#player");
const canvasElementPic = document.querySelector("#canvasPic");
const canvasElementSti = document.querySelector("#canvasSti");
const captureButton = document.querySelector("#capture-btn");
const deleteButton = document.querySelector("#delete-btn");
const imagePicker = document.querySelector("#image-picker");
const imagePickerArea = document.querySelector("#pick-image");
const newImages = document.querySelector("#newImages");
const imageLoc = "uploads/images/";
const stiLoc = "/stickers";
var stickers = false;

const width = 320;
const height = 240;
let zIndex = 1;

const createImage = (src, alt, title, width, height, className) => {
	let newImg = document.createElement("img");

	if (src !== null) newImg.setAttribute("src", src);
	if (alt !== null) newImg.setAttribute("alt", alt);
	if (title !== null) newImg.setAttribute("title", title);
	if (width !== null) newImg.setAttribute("width", width);
	if (height !== null) newImg.setAttribute("height", height);
	if (className !== null) newImg.setAttribute("class", className);

	return newImg;
};

const startMedia = () => {
	if (!("mediaDevices" in navigator)) {
		navigator.mediaDevices = {};
	}

	if (!("getUserMedia" in navigator.mediaDevices)) {
	navigator.mediaDevices.getUserMedia = constraints => {
		const getUserMedia =
		navigator.webkitGetUserMedia || navigator.mozGetUserMedia;

		if (!getUserMedia) {
			return Promise.reject(new Error("getUserMedia is not supported"));
		} else {
		return new Promise((resolve, reject) =>
			getUserMedia.call(navigator, constraints, resolve, reject)
		);
		}
	};
}

  navigator.mediaDevices
    .getUserMedia({ video: true })
    .then(stream => {
    	videoPlayer.srcObject = stream;
    	videoPlayer.style.display = "block";
    })
    .catch(err => {
    	imagePickerArea.style.display = "block";
    });
};

window.addEventListener("load", event => startMedia());