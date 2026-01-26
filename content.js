(() => {
  if (document.getElementById("vo-overlay")) return;


  const overlay = document.createElement("div");
  overlay.id = "vo-overlay";

  const box = document.createElement("div");
  box.className = "box";

  const video = document.createElement("video");
  video.controls = false;
  video.autoplay = true;       
  video.muted = true;   // cant force unmute on chrome, but u can make it so when the user clicks it starts screaming        
  video.loop = true;
  video.playsInline = true;

  video.src = chrome.runtime.getURL("skeleton.mp4");

  box.appendChild(video);
  overlay.appendChild(box);
  document.documentElement.appendChild(overlay);

  overlay.addEventListener("click", () => {
  if (video.muted) {
    video.muted = false;
    video.volume = 1.0;
  }
});

  document.addEventListener("keydown", onKeyDown, true);
})();
