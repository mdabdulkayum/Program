from pytube import Playlist
link=input("Enter YouTube Playlist URL: ")
yt_playlist = Playlist (link)
for video in yt_playlist.videos:
    video.streams.get_highest_resolution ().download ("F:\Program\Python\Project\PlayList")
    print("Video Downloaded: ", video.title)

print("\nAll videos are downloaded.")