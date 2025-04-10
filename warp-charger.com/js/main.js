function carouselNormalization() {
    var items = $('#carouselProducts .carousel-item'), //grab all slides
        heights = [], //create empty array to store height values
        tallest; //create variable to make note of the tallest slide

    if (items.length) {
        function normalizeHeights() {
            items.each(function() { //add heights to array
                heights.push($(this).height());
            });
            tallest = Math.max.apply(null, heights); //cache largest value
            items.each(function() {
                $(this).css('min-height',tallest + 'px');
            });
        };
        normalizeHeights();

        $(window).on('resize orientationchange', function () {
            tallest = 0, heights.length = 0; //reset vars
            items.each(function() {
                $(this).css('min-height','0'); //reset min-height
            });
            normalizeHeights(); //run it again
        });
    }
}

jQuery(document).ready(function( $ ) {
  // Back to top button
  $(window).scroll(function() {
    if ($(this).scrollTop() > 100) {
      $('.back-to-top').fadeIn('slow');
    } else {
      $('.back-to-top').fadeOut('slow');
    }
  });
  $('.back-to-top').click(function(){
    $('html, body').animate({scrollTop : 0},500, 'easeInOutCubic');
    return false;
  });

  // Initiate superfish on nav menu
  $('.nav-menu').superfish({
    animation: {
      opacity: 'show'
    },
    speed: 400
  });

  // Mobile Navigation
  if ($('#nav-menu-container').length) {
    var $mobile_nav = $('#nav-menu-container').clone().prop({
      id: 'mobile-nav'
    });
    $mobile_nav.find('> ul').attr({
      'class': '',
      'id': ''
    });
    $('body').append($mobile_nav);
    $('body').prepend('<button type="button" id="mobile-nav-toggle"><i class="fa fa-bars"></i></button>');
    $('body').append('<div id="mobile-body-overly"></div>');
    $('#mobile-nav').find('.menu-has-children').prepend('<i class="fa fa-chevron-down"></i>');

    $(document).on('click', '.menu-has-children i', function(e) {
      $(this).next().toggleClass('menu-item-active');
      $(this).nextAll('ul').eq(0).slideToggle();
      $(this).toggleClass("fa-chevron-up fa-chevron-down");
    });

    $(document).on('click', '#mobile-nav-toggle', function(e) {
      $('body').toggleClass('mobile-nav-active');
      $('#mobile-nav-toggle i').toggleClass('fa-times fa-bars');
      $('#mobile-body-overly').toggle();
    });

    $(document).click(function(e) {
      var container = $("#mobile-nav, #mobile-nav-toggle");
      if (!container.is(e.target) && container.has(e.target).length === 0) {
        if ($('body').hasClass('mobile-nav-active')) {
          $('body').removeClass('mobile-nav-active');
          $('#mobile-nav-toggle i').toggleClass('fa-times fa-bars');
          $('#mobile-body-overly').fadeOut();
        }
      }
    });
  } else if ($("#mobile-nav, #mobile-nav-toggle").length) {
    $("#mobile-nav, #mobile-nav-toggle").hide();
  }

  // Smooth scroll for the menu and links with .scrollto classes
  $('.nav-menu a, #mobile-nav a, .scrollto').on('click', function() {
    if (location.pathname.replace(/^\//, '') == this.pathname.replace(/^\//, '') && location.hostname == this.hostname) {
      var target = $(this.hash);
      if (target.length) {
        var top_space = 0;

        if ($('.header').length) {
          top_space = $('.header').outerHeight();
        }

        $('html, body').animate({
          scrollTop: target.offset().top - top_space
        }, 500, 'easeInOutCubic');

        if ($(this).parents('.nav-menu').length) {
          $('.nav-menu .menu-active').removeClass('menu-active');
          $(this).closest('li').addClass('menu-active');
        }

        if ($('body').hasClass('mobile-nav-active')) {
          $('body').removeClass('mobile-nav-active');
          $('#mobile-nav-toggle i').toggleClass('fa-times fa-bars');
          $('#mobile-body-overly').fadeOut();
        }
        return false;
      }
    }
  });

  if($('body').is("#api_body")) {
    $('#mobile-nav-toggle').addClass('header-scrolled');
  }

  // Header scroll class
  $(window).scroll(function() {
    if ($(this).scrollTop() > 100) {
      $('#header').addClass('header-scrolled');
      $('#mobile-nav-toggle').addClass('header-scrolled');
    } else if(!($('body').is("#api_body"))) {
      $('#header').removeClass('header-scrolled');
      $('#mobile-nav-toggle').removeClass('header-scrolled');
    }
  });


    //intro carousel
  const introCarousel = document.getElementById('introCarousel')
  if (introCarousel != null) {
    const carousel = new bootstrap.Carousel(introCarousel);
  }

  //product carousel
  const productCarousel = document.getElementById('carouselProducts')
  if (productCarousel != null) {
    const carousel = new bootstrap.Carousel(productCarousel);

    productCarousel.addEventListener('slide.bs.carousel', event => {
        document.querySelector('#carouselProducts .custom-carousel-indicators .active').classList.remove("active");
        document.querySelector(`#carouselProducts .custom-carousel-indicators [data-bs-slide-to="${event.to}`).classList.add("active");
    });

    carouselNormalization();
  }

  // Impressions isotope and filter
  var impressionsIsotope = $('.impressions-container').isotope({
    itemSelector: '.impressions-item',
    layoutMode: 'fitRows'
  });

  $('#impressions-flters li').on( 'click', function() {
    $("#impressions-flters li").removeClass('filter-active');
    $(this).addClass('filter-active');

    impressionsIsotope.isotope({ filter: $(this).data('filter') });
  });

  lightbox.option({
    'resizeDuration': 0,
    'imageFadeDuration': 0,
    'fadeDuration': 0,
    'wrapAround': true,
    'albumLabel': "Bild %1 von %2"
  })

  $(window).on('activate.bs.scrollspy', function (e) {
    setTimeout(() => {
        $('#navbar a.active').parents("div.collapse").prev().addClass("active");
        $('#navbar a:not(.active)').next("div").collapse('hide');
        $('#navbar a.active').next("div").filter(":not(.show)").collapse('show');
        }, 100);
    });

  $('#navbar a.active').parents("div.collapse").prev().addClass("active");
  $('#navbar a:not(.active)').next("div").collapse('hide');
  $('#navbar a.active').next("div").filter(":not(.show)").collapse('show');
});
