require 'watir' # Crawler

username = 'Your username'
password = 'Your password'
like_counter = 0
day_counter = 0;
MAX_LIKES = 350

# Open Browser, Navigate to Login page
browser = Watir::Browser.new :chrome, switches: ['--incognito']
browser.goto "instagram.com/accounts/login/"

# Navigate to Username and Password fields, inject info
browser.text_field(:name => "username").set "#{username}"
browser.text_field(:name => "password").set "#{password}"

# Click Login Button
browser.button(:class => '_0mzm- sqdOP  L3NKy       ').click
sleep(5)
browser.button(:class=> "aOOlW   HoLwm ").click

while true
while day_counter < 6
# Continuous loop to break upon reaching the max likes
  while like_counter < MAX_LIKES    
	while browser.span(:class => "glyphsSpriteHeart__outline__24__grey_9 u-__7").exists?
	   browser.span(:class => "glyphsSpriteHeart__outline__24__grey_9 u-__7").click
	   sleep(3)
	   like_counter += 1 
	end
  browser.driver.execute_script("window.scrollBy(0,document.body.scrollHeight)")
  sleep(1)
  end
  sleep(3600)
day_counter+=1
like_counter = 0
end
sleep(86400)
day_counter = 0
end
 