require 'watir'

  username = "Your username"
  password = "Your password"

  user = "Page you want to visit"

  #open browser, navigate to login page
  browser = Watir::Browser.new :chrome, switches: ['--incognito']
  browser.goto "https://www.instagram.com/accounts/login/"

  #log into instagram
  browser.text_field(:name => "username").set "#{username}"
  browser.text_field(:name => "password").set "#{password}"

  #Click login button
  browser.button(:class => '_0mzm- sqdOP  L3NKy       ').click
  sleep(2)


  browser.goto "instagram.com/#{user}/"
  sleep(3)
  browser.a(:'href' => "/#{user}/following/").click
  sleep(2)

  dayCounter = 0
  hourCounter = 0

while true
while dayCounter < 1000
  while hourCounter < 100
        if browser.button(:class => '_0mzm- sqdOP  L3NKy   _8A5w5    ').exists?
                browser.button(:class => '_0mzm- sqdOP  L3NKy   _8A5w5    ').click
                sleep(2)
		browser.button(:class => 'aOOlW -Cab_').click
		hourCounter += 1
		sleep(2)
        end
  end

  hourCounter = 0       #Reset Hourly Counter
  dayCounter += 100      #Followers per day counter
  #browser.driver.execute_script("window.scrollBy(0, document.body.scrollHeight$
  sleep(3600)           #Sleep for an hour
end
dayCounter = 0
hourCounter = 0
end
